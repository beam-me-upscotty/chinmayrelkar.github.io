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

 	$sqlquery = "select * from passtable";

   	$result = $mysqli->query($sqlquery);

 	if($result->num_rows > 0)
 	{
 	    	while($row = $result->fetch_assoc()) 
	    	{
    			
        			if($row["firstname"] === $firstname)
        			{	
        				if($row["Password"] === $password)
        				{	
        					session_start();
        					$_SESSION['LOGIN'] = $row["firstname"];
        					header('Location: /Start-here/owe You/work.php');
        					exit;
        				}
        				else 
        				{
        					echo 'INCORRECT PASSWORD';
        					break;
        				}
        			}
        		}	
 	}
 	else
 		echo "FAIL end".$mysqli->error;
 	?>
