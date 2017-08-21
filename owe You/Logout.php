<?php
	
	session_start();	
	if(isset($_SESSION['LOGIN']))
		unset($_SESSION['LOGIN']);
	header('Location: /Start-here/owe You/myfirst.php');
    exit;
        					
?>
