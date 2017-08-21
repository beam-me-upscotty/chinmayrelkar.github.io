<?php 
	$servername = "localhost";
 	$username = "root";
 	$password = " ";
 	$dbname = "firstdb";
 	$mysqli = new mysqli($servername, $username, $password, $dbname);
	$firstname = $_POST['fn'];
	$password = $_POST['ps'];
	
	if($mysqli->connect_error)
 	{
 		die('failed to add database' );	
 	}

 	$sqlquery = 'insert into passtable values("'.$firstname.'","'.$password.'")';

    if($mysqli->query($sqlquery))
        header('Location: /Start-here/owe You/myfirst.php');
 	else
 		echo "FAIL end".$mysqli->error;
 	?>
