<!DOCTYPE html>
<html>
<head>
	<title>Insert Data into MySQL Database</title>
</head>
<body>
	<h2>Insert Data into MySQL Database</h2>
	<form method="post" action="<?php $_SERVER['PHP_SELF'];?>">
		<label for="name">Name:</label>
		<input type="text" id="name" name="name"><br><br>
		
		<label for="roll">Roll:</label>
		<input type="text" id="roll" name="roll"><br><br>
		
		<label for="email">Email:</label>
		<input type="email" id="email" name="email"><br><br>
		
		<input type="submit" value="Submit">
	</form>
</body>
</html>


<?php
$dbHost = 'localhost';
$dbUsername = 'root';
$dbPassword = '';
$dbName = 'csit';

$conn = mysqli_connect($dbHost, $dbUsername, $dbPassword, $dbName);

if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
    exit();
}
if($_SERVER['REQUEST_METHOD'] == 'POST'){
	
	$username = mysqli_real_escape_string($conn, $_POST['name']);
	$roll = mysqli_real_escape_string($conn, $_POST['roll']);
	$email = mysqli_real_escape_string($conn, $_POST['email']);

	$sql = "INSERT INTO user (username, rollno, email) VALUES ('$username', '$roll', '$email')";
	if (mysqli_query($conn, $sql)) {
		echo "Data inserted successfully!";
	} else {
		echo "Error: " . $sql . "<br>" . mysqli_error($conn);
	}
}

mysqli_close($conn);
?>
