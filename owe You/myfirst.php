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
	if(isset($_SESSION['LOGIN']))
		header("location: /Start-here/owe You/work.php");
?>

<body>
	<div class="container-fluid navbar ">
		<div class="button-class" style="display:inline-block; ">
		Chinmay's Database
		</div>	
	</div>


	<div class = "container-fluid" >
		<div class="col-sm-2">
		</div>
		<div class="col-sm-4 form-class-base-col" id="LoginForm">
		<div class="form-class-base">
		
		<div class="text-center title" >
			Login
		</div>


		<div class="text-center" style="padding: 30px;">
				
		<form action="add_entry.php" method="post" class="form text-center" >
 					
			<div class="form-group">
			<input type="text" class = "form-control" name ="fn" placeholder="User Id" required="required">
			</div>
  				
			<div class="form-group">
			<input type="password" class = "form-control" name ="ps" placeholder="Password" required="required">
			</div>
  			
			<div style="text-align:center;">
		 	<button type="submit" class="button-class-fab">Login</button>
			</div>
		</form>
		</div>
	</div>
	</div>
	<div class="col-sm-4 form-class-base-col" id="LoginForm">
		<div class="form-class-base">
		
		<div class="text-center title" >
			Sign up
		</div>


		<div class="text-center" style="padding: 30px;">
				
		<form action="add_user.php" method="post" class="form text-center" >
 					
			<div class="form-group">
				<input type="text" class = "form-control" name ="fn" placeholder="User Id" required="required">
			</div>
  				
			<div class="form-group">
				<input type="password" class = "form-control" name ="ps" placeholder="Password" required="required">
			</div>
  			
			<div style="text-align:center;">
		 		<button type="submit" class="button-class-fab">Sign Up</button>
			</div>

		</form>
		</div>
	</div>
	</div>
	<div class="col-sm-2">
	</div>
	</div>
</body>
</html>
