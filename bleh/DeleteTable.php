<?php 
	$servername = "localhost";
 	$username = "root";
 	$password = "8736";
 	$dbname = "firstdb";
	$mysqli = new mysqli($servername, $username, $password, $dbname);
	if($mysqli->connect_error)
 	{
 		die('failed to add database' );	
 	}

 	$sqlquery = " drop table student";
 	if($mysqli->query($sqlquery))
 	{
 		header("location:myfirst.php");
 		exit;
 	}
 	else
 		echo 'ERROR MESSAGE'.$mysqli->error;
?>
