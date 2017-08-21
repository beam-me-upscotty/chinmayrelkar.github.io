<?php
	// to check if any session is on going
	session_start();
	if(!isset($_SESSION['LOGIN']))
		header("location: /owe You/myfirst.php");

	$servername = "localhost";
 	$username = "root";
 	$password = " ";
 	$dbname = "firstdb";
 	$mysqli = new mysqli($servername, $username, $password, $dbname);
	$name = $_POST['name'];
	$money = $_POST['mon'];
	$reason = $_POST['res'];

	if($mysqli->connect_error)
 	{
 		die('failed to use database' );	
 	}

 	$sqlquery = 'insert into owe values( NULL,"'.$_SESSION['LOGIN'].'","'.$name.'",'.$money.',"'.$reason.'")';

   	if( !$mysqli->query($sqlquery))
   		$mysqli->error_log("oh");
   	else 
		header("location: /Start-here/owe You/work.php");

	?>
