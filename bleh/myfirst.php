<!DOCTYPE html>
<html>
<head>

<link href="bootstrap-3.3.7-dist/css/bootstrap.min.css" rel="stylesheet"> 
<link href="mystylesheet.css" rel="stylesheet"> 
	<title>First script</title>
</head>


<body>
	<div class="container-fluid navbar ">
		<div class="button-class" style="display:inline-block; "	onclick="func3()">Chinmay's Database</div>
		<div class="button-class restrict" id="show" onclick="displayTable()">TABLE</div>
		<div class="button-class restrict" id="hide" onclick="hideTable()" style="display: none;">FORM</div>
	</div>




	<div class = "container-fluid" >
	<div class="col-sm-2">
	</div>
	<div class="col-sm-8 form-class-base-col" id="blehbleh">
	<div class="form-class-base">
		
		<div class="text-center title" >
			Get Your Name on the list
		</div>

		<div class="container">
			
		<div 	
			class="col-sm-4 text-center" 
			style="	border-right: solid 1px white;
					padding: 40px;">
		
			<img src="add_user_icon.png">
			
		</div>

		<div class="col-sm-4 text-center" style="padding: 30px;">
				
		<form action="add_entry.php" method="post" class="form text-center" >
 					
			<div class="form-group">
			<input type="text" class = "form-control" name ="fn" placeholder="First Name" required="required">
			</div>
  				
			<div class="form-group">
			<input type="text" class = "form-control" name ="ps" placeholder="Password" required="required">
			</div>
  			
			<div style="text-align:center;">
		 	<button type="submit" class="button-class-fab"><span class="glyphicon glyphicon-plus"></span></button>
			</div>
		</form>
		</div>
		
		</div>
	</div>
	</div>
	<div class="col-sm-2">
	</div>
	</div>

	<div class="container" >
	<?php
 		
 		$servername = "localhost";
 		$username = "root";
 		$password = "8736";
 		$dbname = "dbcore";

 		$mysqli = new mysqli($servername, $username, $password);
 		
 		if($mysqli->connect_error)
 		{
 			die('<div class="container-fluid" style = "background-color :#f00;">Connection Failed</div>' );	
 		}
		
		$mysqli->query("Create database if not exists firstdb");
		$mysqli->select_db("firstdb");
		
		$sql = "SELECT  * FROM passtable";
	   	$result = $mysqli->query($sql);

		if ($result->num_rows > 0) 
		{
    		// output data of each row
   		 	echo '<div class="container text-center table-class" id ="tttt" style = "display : none;">
   		 				<div class="container text-center title" >The List</div>
   		 				<table class="table" >
    						
    							<tr>
    							<th>Login</th>
    							<th>Password</th>
    							</tr>
    						';
	
	    	while($row = $result->fetch_assoc()) 
	    	{
    			echo 	" <tr><th> " 
        				.$row["firstname"]
        				."</th><th> "
        				.$row["Password"]
        				."</th></tr>";
    		}	
    		
    		echo '</table></div>';
		} 
		else 
		{
    		echo '<div class="navbar button-class" style=" margin-top: 5px;"> NO RECORDS IN THE TABLE<div>';
		}

		$mysqli->close();	
  	?>
	</div>	


</body>

<script type="text/javascript">
	function displayTable(){
		document.getElementById("tttt").style.display = 'block';
		document.getElementById("show").style.display = 'none';
		document.getElementById("hide").style.display = 'block';
		document.getElementById("blehbleh").style.display = 'none';
	}

	function hideTable(){
		document.getElementById("tttt").style.display = 'none';
		document.getElementById("show").style.display = 'block';
		document.getElementById("hide").style.display = 'none';
			document.getElementById("blehbleh").style.display = 'block';
	
	}
	function funcdelete()
	{
		document.location.href='DeleteTable.php';
	}

</script>
</html>
