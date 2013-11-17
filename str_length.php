<?php

$str = 'PHP语言';

echo strlen($str), PHP_EOL; // 9

echo mb_strlen($str, 'UTF-8'), PHP_EOL; // 5

echo mb_strwidth($str, 'UTF-8'), PHP_EOL; // 7
