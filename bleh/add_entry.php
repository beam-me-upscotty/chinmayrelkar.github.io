<?php 
	$servername = "localhost";
 	$username = "root";
 	$password = "8736";
 	$dbname = "firstdb";
	$mysqli = new mysqli($servername, $username, $password, $dbname);
	$firstname = $_POST['fn'];
	$password = $_POST['ps'];
	if($mysqli->connect_error)
 	{
 		die('failed to add database' );	
 	}

 	$sqlquery = "select * from passtable";

   	$result = $mysqli->query($sqlquery);

 	if($result->num_rows > 0)
 	{
 	    	while($row = $result->fetch_assoc()) 
	    	{
    			
        			if($row["firstname"] === $firstname)
        			{	
        				if($row["Password"] === $password)
        					echo 'Done';
        				else 
        				{
        					echo 'Fail-in';
        					break;
        				}
        			}
        		}	
 	}
 	else
 		echo "FAIL end".$mysqli->error;
 	?>
