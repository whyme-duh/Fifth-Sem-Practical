<!DOCTYPE html>
<html>
<body>


<?php
	$assocArr = array(
	"apple" => 3,
	"banana" => 2,
	"orange" => 4,
	"kiwi" => 1,
	"mango" => 5,
	"grape" => 6
	);

	ksort($assocArr);
	echo "Array sorted in ascending order of key: \n";
	echo "<pre>";
	print_r($assocArr);

	arsort($assocArr);
	echo "\nArray sorted in descending order of value: \n";
	echo "<pre>";
	print_r($assocArr);
?>




</body>
</html>
