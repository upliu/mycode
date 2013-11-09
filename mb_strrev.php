<?php

$str = '记者从有关人士处获some-letters-here悉嫦娥二号发射的各项准备工作全部就绪';

echo mb_strrev($str);

function mb_strrev($str) {
	$len = mb_strlen($str, 'UTF-8');
	$arr = array();
	for ($i = 0; $i < $len; $i++) {
		$arr[] = mb_substr($str, $i, 1, 'UTF-8');
	}
	return implode('', array_reverse($arr));
}
