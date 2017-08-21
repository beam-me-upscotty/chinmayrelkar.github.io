<!DOCTYPE html>
<html>
<head>

<link href="bootstrap-3.3.7-dist/css/bootstrap.min.css" rel="stylesheet"> 
<link href="mystylesheet.css" rel="stylesheet"> 
<meta charset="utf-8">
         <meta name="viewport" content="width=device-width, initial-scale=1">
         
	<title>First script</title>
</head>

<?php
	// to check if any session is on going
	session_start();
	if(!isset($_SESSION['LOGIN']))
		header("location: /Start-here/owe You/myfirst.php");
?>
<body>
	
	<div class="container-fluid navbar ">
		<div class="button-class" style="display:inline-block; ">
		Chinmay's Database
		</div>	
	
		<div class="button-class restrict" onclick="funcLogout()">Log Out</div>	
		<div class="button-class restrict" id="button_form" onclick="funcShowForm()">Add Entry</div>	
		<div class="button-class restrict" id="button_table" style="display: none;" onclick="funcShowTable()">Table</div>	
	</div>
	<?php
 		
 		$servername = "localhost";
 		$username = "root";
 		$password = " ";
 		$dbname = "dbcore";
		
 		
		$mysqli = new mysqli($servername, $username, $password);
 		
 		if($mysqli->connect_error)
 		{
 			die('<div class="container-fluid" style = "background-color :#f00;">Connection Failed</div>' );	
 		}
		session_start();
			
		$Login_Global = $_SESSION['LOGIN'];
		
		$mysqli->select_db("firstdb");
		
		
		$PAYEE = "-";
		$sql = 'SELECT  * FROM passtable WHERE firstname != "'.$Login_Global.'"';
	   	$resultowe = $mysqli->query($sql);

		if ($resultowe->num_rows > 0) 
		{
		// output data of each row
	 	echo ' 
	 		
	 		<div class="container text-center table-class" id ="table_id" >
 			<div class="container text-center title" >Welcome '.$_SESSION['LOGIN'].'</div>
 			<table class="table" >
			<tr>
			<th>Name</th>
			<th>Money</th>
			</tr>';

	    	while($row = $resultowe->fetch_assoc()) 
	    	{	
	    		$sqlquery1 = ' SELECT * FROM owe WHERE (FIRSTNAME = '
	    			.'"'.$_SESSION["LOGIN"].'"'
	    			.' and SECONDNAME = '
	    			.'"'.$row["firstname"].'")';

	    		$sqlquery2 = ' SELECT * FROM owe WHERE  (FIRSTNAME = '
    				.'"'.$row["firstname"].'"'
    				.' and SECONDNAME = '
    				.'"'.$_SESSION["LOGIN"].'")';
    				
    			if(!$mysqli->query($sqlquery1))
    				echo $mysqli->error;
    			if(!$mysqli->query($sqlquery2))
    				echo $mysqli->error;
    			
		    	$resultquery1 = $mysqli->query($sqlquery1);
				$resultquery2 = $mysqli->query($sqlquery2);
			

				$money = 0;
	    	
	   	 		while($rowquery1 = $resultquery1->fetch_assoc()) 
	   	 			$money = $money + $rowquery1["MONEY"];
				while($rowquery2 = $resultquery2->fetch_assoc()) 
	   	 			$money = $money - $rowquery2["MONEY"];
	    			    		


    			echo 	' <tr 
    			onclick="document.location.href=\'work.php?gid='.$row['firstname'].'\'"><th>'
        				.$row['firstname']
        				.'</th><th> '
        				.$money
        				.'</th></tr>';
    		
    		}
    		
    		echo '</table></div>';
		} 
		else 
		{
    			echo '<div class="navbar button-class" style=" margin-top: 5px;"> NO RECORDS IN THE TABLE<div>';
		}
		

  	?>
	</div>


<!-- this is to add entries to <select> in record add form-->
	<div class = "container-fluid" id="add_record_form" style="display: none;">
		<div class="col-sm-4">
		</div>
		<div class="col-sm-4 form-class-base-col" >
			<div class="form-class-base">
				<div class="text-center title" >Entry Form</div>

				<div class="text-center" style="padding: 25px;">
					<form action="add_record.php" method="post" class="form text-center" >

					<div class="form-group">
					<?php		
						$sql = 'SELECT  * FROM passtable WHERE firstname != "'.$Login_Global.'"';
				   		$resultowe = $mysqli->query($sql);
		   				echo $mysqli->num_rows;
			   			echo '<select name="name" class = "form-control" placeholder="Name" required="required">';
						if ($resultowe->num_rows > 0) 
						{
							while($row = $resultowe->fetch_assoc())
							{
								echo '<option value="'.$row["firstname"].'">'.$row["firstname"].'</option>';			
							}
						}
						$mysqli->close();
					?>
						</select>
					</div>

					<div class="form-group">
						<input type="number" class = "form-control" name ="mon" placeholder="Amt. of Money" required="required">
					</div>
  			
  					<div class="form-group">
						<input type="text" class = "form-control" name ="res" placeholder="Reason" required="required">
					</div>
  				
					<div style="text-align:center;">
					 	<button type="submit" class="button-class-fab"><span class="glyphicon glyphicon-plus"></span></button>
					</div>

					</form>
				</div>
			
			</div>
		</div>
	</div>
	
	<?php

		if(isset($_GET['gid']))
		{

 		$servername = "localhost";
 		$username = "root";
 		$password = " ";
 		$dbname = "dbcore";
		
		$mysqli = new mysqli($servername, $username, $password);
 		
 		if($mysqli->connect_error)
 		{
 			die('<div class="container-fluid" style = "background-color :#f00;">Connection Failed</div>' );	
 		}
		
 		$mysqli->select_db("firstdb");	

				
				$sql1= 'SELECT  * FROM owe WHERE firstname = "'.$Login_Global.'" and secondname = "'.$_GET['gid'].'"';
				$sql2 = 'SELECT  * FROM owe WHERE firstname = "'.$_GET['gid'].'" and secondname = "'.$Login_Global.'"';
				   		if(!$mysqli->query($sql1))
				   			echo 'some problem';
				   		else
				   		{	
				   			
				   			echo '
		   							<div class="container text-center table-class" id ="table_id" >
		   							<div 
		   									onclick="document.location.href=\'work.php\'"
		   									class="button-class" 
		   									style="float:right;margin-right:15px;margin-top:0px;">close</div>
					 				<div class="container text-center title" >Your records with '.$_GET['gid'].'</div>
 									<table class="table" >
									<tr>
									<th><h3>Money</h3></th>
									<th><h3>Reason</h3></th>
									</tr>';

		   					$resultowe = $mysqli->query($sql1);
		   					$records_exists = 0;
		   					if ($resultowe->num_rows > 0) 
							{
								$records_exists = 1;

								while($row = $resultowe->fetch_assoc())
								{
									echo 
											'<tr>
												<th>'.$row['MONEY'].'</th>'
												.'<th>'.$row['REASON'].'</th>
											</tr>';		
								}
							}
							$resultowe = $mysqli->query($sql2);
		   					if ($resultowe->num_rows > 0) 
							{
								$records_exists = 1;
								while($row = $resultowe->fetch_assoc())
								{
									echo '<tr><th>'.(-1*$row['MONEY'])
											.'</th>'
											.'<th>'.$row['REASON']
											.'</th></tr>';		
								}
							}
							if($records_exists === 0)
							{
								echo '<tr><h3>No Records found</h3></tr>';
							}
							echo "</table></div>";
							$mysqli->close();	
		   				}
		}
	?>
	</body>
	<script > 
	function funcLogout()
	{
		document.location.href='Logout.php';
	}
	function funcShowForm()
	{
		document.getElementById("add_record_form").style.display="block";
		document.getElementById("table_id").style.display="none";
		document.getElementById("button_form").style.display="none";
		document.getElementById("button_table").style.display="block";
			
	}
	function funcShowTable()
	{
		document.getElementById("add_record_form").style.display="none";
		document.getElementById("table_id").style.display="block";
		document.getElementById("button_form").style.display="block";
		document.getElementById("button_table").style.display="none";
			
	}

	</script>

	</html>	

