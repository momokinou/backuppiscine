<?php
session_start();
if (isset($_POST["submit"]) && $_POST["submit"] != "OK")
    $login = 0;
else
{
    if ((isset($_POST["passwd"]) && !empty($_POST["passwd"]))
    && isset($_POST["login"]) && !empty($_POST["login"]))
    {
        if (!file_exists("../private/passwd"))
            $login = 0;
        else
        {
            if (file_exists("../private/passwd"))
                $array = unserialize(file_get_contents("../private/passwd"));
            if (!isset($array[$_POST["login"]]))
                $login = 0;
            else if (hash("whirlpool", $_POST["passwd"]) != $array[$_POST["login"]]["passwd"])
                $login = 0;
            else
                $login = 1;
        }
    }
    else
        $login = 0;
}
if ($login == 1)
{
    $_SESSION["email"] = $_POST["login"];
    $_SESSION["firstname"] = $array[$_POST["login"]]["firstname"];
    $_SESSION["lastname"] = $array[$_POST["login"]]["lastname"];
    $_SESSION["login"] = $_SESSION["firstname"]." ".$_SESSION["lastname"];
}
echo "<div style=\"display: none\" id=\"login\">".($login ? "OUI" : "NON")."</div>";
include("index.php");


?>