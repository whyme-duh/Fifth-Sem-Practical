<!DOCTYPE html>
<html>
<body>

<?php
function shiftArray($arr, $shiftCount) {
    $count = count($arr);
    $shiftCount = $shiftCount % $count;

    if ($shiftCount < 0) {
        $shiftCount += $count;
    }

    for ($i = 0; $i < $shiftCount; $i++) {
        $temp = $arr[0];
        for ($j = 0; $j < $count - 1; $j++) {
            $arr[$j] = $arr[$j+1];
        }
        $arr[$count-1] = $temp;
    }

    return $arr;
}
$arr = array(1, 2, 3, 4, 5);
$shiftedArr = shiftArray($arr, 2);
print_r($shiftedArr);

?>

</body>
</html>
