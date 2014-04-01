<?php

/**
 * curl 函数，如果出错会抛出异常，所以请调用此函数时使用 try{}catch(){} 的方式
 * @param string $url
 * @param array $postFields
 * @return string
 * @throws Exception
 */
function curl($url, $postFields = array())
{
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_FAILONERROR, false);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_TIMEOUT, 30);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 10);
        //https 请求
        if(strlen($url) > 5 && strtolower(substr($url,0,5)) == "https" ) {
                curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
                curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, false);
        }

        if (is_array($postFields) && 0 < count($postFields))
        {
                $postBodyString = "";
                $postMultipart = false;
                foreach ($postFields as $k => $v)
                {
                        if("@" != substr($v, 0, 1))//判断是不是文件上传
                        {
                                $postBodyString .= "$k=" . urlencode($v) . "&";
                        }
                        else//文件上传用multipart/form-data，否则用www-form-urlencoded
                        {
                                $postMultipart = true;
                        }
                }
                unset($k, $v);
                curl_setopt($ch, CURLOPT_POST, true);
                if ($postMultipart)
                {
                        curl_setopt($ch, CURLOPT_POSTFIELDS, $postFields);
                }
                else
                {
                        curl_setopt($ch, CURLOPT_POSTFIELDS, substr($postBodyString,0,-1));
                }
        }
        $reponse = curl_exec($ch);

        if (curl_errno($ch))
        {
                throw new Exception(curl_error($ch),0);
        }
        else
        {
                $httpStatusCode = curl_getinfo($ch, CURLINFO_HTTP_CODE);
                if (200 !== $httpStatusCode)
                {
                        throw new Exception($reponse,$httpStatusCode);
                }
        }
        curl_close($ch);
        return $reponse;
}
