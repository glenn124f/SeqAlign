<!DOCTYPE html>
<head><link rel="stylesheet" type="text/css" href="main.css"></head>
<title>Needleman Wunch Algorithm</title>
<body>
    <div id="tt">
        <tt id="tt1">ALIGNMENT</tt>
    </div>

    <div id="menu">
        <div id="nav">
            <ul>
                <li><a>HOME</a></li>
                <li><a>LINK1</a></li>
                <li><a>LINK2</a></li>
                <li><a>LINK3</a></li>
                <li><a>LINK4</a></li>
            </ul>
        </div>
    </div>
    
    <div class="f1">
        <div id="h11">NEEDLEMAN WUNSCH ALGORITHM</div>
        <form action="process.php" method="post" class="f11">
            Enter sequence 1&nbsp;&nbsp;&nbsp; : <input type="text" name="s1" id="s1" ><br>
            Enter sequence 2&nbsp;&nbsp;&nbsp; : <input type="text" name="s2" id="s2"><br>
            Score for match  &nbsp;&nbsp;&nbsp;&nbsp;   : <input type="number" name="m" id="m"><br>
            Score for mismatch : <input type="number" name="mm" id="mm"><br>
            Gap penalty&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;       : <input type="number" name="gp" id="gp"><br>
            <input type="submit" name="sbtn" id="sbtn" value="Align Globally">
        </form>
    </div>
    <div class="f1">
    <div id="h11">SMITH WATERMAN ALGORITHM</div>
        <form action="process1.php" method="post" class="f11">
            Enter sequence 1&nbsp;&nbsp;&nbsp; : <input type="text" name="s1" id="s1"><br>
            Enter sequence 2&nbsp;&nbsp;&nbsp; : <input type="text" name="s2" id="s2"><br>
            Score for match  &nbsp;&nbsp;&nbsp;&nbsp;   : <input type="number" name="m" id="m"><br>
            Score for mismatch : <input type="number" name="mm" id="mm"><br>
            Gap penalty&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;       : <input type="number" name="gp" id="gp"><br>
            <input type="submit" name="sbtn" id="sbtn" value="Align Locally">
        </form>
    </div>
   <!-- <footer>Developed by Glenn and Pranaydeep</footer>
    -->
    <scipt>
        
    </scipt>
</body>
</html>