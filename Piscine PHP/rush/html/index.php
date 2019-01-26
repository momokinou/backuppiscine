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
    <link rel="stylesheet" type="text/css" media="screen" href="../css/signup.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="../css/showcase.css" />
</head>
<body>
    <?php include("./header.php"); ?>
    <div id="feedback" class="feedback">
        <div class="feedback-content">
            <span class="close">&times;</span>
            <p id="login_message"></p>
            <p id="logout_message"></p>
        </div>
    </div>

    <div id="showcase">
        <table id="articles">
            <tr class="row">
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td>
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td> 
                <td class="column"><img class="product" src="../img/titoushop.png"></td>
            </tr>
            <tr class="row">
                <td class="column"><img class="product" src="../img/titoushop.png"></td>
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td> 
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td>
            </tr>
            <tr class="row">
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td>
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td> 
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td>
            </tr>
            <tr class="row">
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td>
                <td class="column"><img class="product" src="../img/titoushop.png"></td>
                <td class="column"><img class="product" src="../img/placeholder.jpg"></td>
            </tr>
        </table>
    </div>

    <script type="text/javascript" src="../js/modal.js"></script>
</body>
</html>