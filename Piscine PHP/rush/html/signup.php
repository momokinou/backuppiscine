<!DOCTYPE <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Titou Shop</title>
    <link rel="stylesheet" type="text/css" media="screen" href="../css/signup.css" />
</head>
<body>
    <?php include("./header.php"); ?>
    <div id="main">
        <form action="./create_acc.php" method="post">
            <div id="form_first">
                <b>First name:</b><br><input type="text" name="firstname" maxlength="20" minlength="3" placeholder="Between 3 and 20 characters"/><br>
                <b>Last name:</b><br><input type="text" name="lastname" maxlength="20" minlength="3" placeholder="Between 3 and 20 characters"/><br>
                <b>E-mail:</b><br><input type="text" name="email" placeholder="example@domain.com" /><br>
            </div>
            <div id="form_second">
                <b>Password:</b><br><input type="password" name="passwd" maxlength="20" minlength="6" placeholder="Between 6 and 20 characters"/><br>
                <b>Verify password</b><br><input type="password" name="verif_passwd" placeholder="Verify password" /><br>
                <button id="createacc" type="submit" name="submit" value="OK">Create Account</button>
            </div>
        </form>
    </div>
    <div id="feedback" class="feedback">
        <div class="feedback-content">
            <span class="close">&times;</span>
            <p id="signup_message"></p>
        </div>
    </div>
    <script type="text/javascript" src="../js/modal.js"></script>
</body>
</html>