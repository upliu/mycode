<?php

$n = $argv;
unset($n[0]);
for ($i = 2; $i < count($n); $i++) {
	$j = $i - 1;
	$key = $n[$i];
	while ($j > 0 && $n[$j] > $key) {
		$n[$j+1] = $n[$j];
		$j--;
	}
	$n[$j+1] = $key;
}

for ($i = 1; $i < count($n); $i++) {
	echo $n[$i], ' ';
}
