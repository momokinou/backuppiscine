<?php
    if(!isset($_SESSION)) 
    { 
        session_start(); 
    } 
?>

<!DOCTYPE <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Titou Shop</title>
    <link rel="stylesheet" type="text/css" media="screen" href="../css/header.css" />
</head>
<body>

    <div id="header">
        <div id="categories">
            <a href="homme.php">HOMME</a>
            <a href="#">FEMME</a>
        </div>
        <a href="./index.php"><div id="logodiv">
            <img id="logo" src="../img/titoushop.png" alt="titoushop logo">
        </div></a>
        <div id="user">
            <a href="#" class="elem panier">PANIER</a>
            <a href="#">
                <?php
                    if (isset($_SESSION["login"]))
                        echo "<a class=\"elem user\"><b>".$_SESSION["firstname"]."<br>".$_SESSION["lastname"]."<b></a>";
                    else
                        echo    "<div class=\"elem auth\">
                                    <a href=\"./signup.php\">SIGN UP</a>
                                    <div onmouseenter=\"dropdown()\" onmouseleave=\"hide_dropdown()\" class=\"dropdown\">
                                        <span class=\"login\">LOGIN</span>
                                        <div id=\"dropdown-login\" class=\"dropdown-content\">
                                            <form autocomplete=\"off\" id=\"login-form\" action=\"login.php\" method=\"post\">
                                                <input type=\"text\" name=\"login\" placeholder=\"E-mail Address\"><br>
                                                <input type=\"password\" name=\"passwd\" placeholder=\"Password\"><br>
                                                <button name=\"submit\" value=\"OK\">Login</button>
                                            </form>
                                        </div>
                                    </div>
                                </div>";
                ?>
            </a>
        </div>
    </div>

    <?php

        if (isset($_SESSION["login"]))
        {
            echo "<a href=\"logout.php\"><div id=\"logout\"><div id=\"logouttext\">Log out</div></div></a>";
        }

    ?>
    
</body>
</html>