<!DOCTYPE html>
<head></head>
<title>ALIGNMENT</title>
<style>
    #line{
        font-family: monospace;
        font-size: 20px;
    }  
</style>
<body>
    <div id="seq">
        
        <?php
            $s1=$_POST["s1"];
            $s2=$_POST["s2"];
            $s1l=strlen($s1);
            $s2l=strlen($s2);
     
            $gp=$_POST["gp"];
            $m=$_POST["m"];
            $mm=$_POST["mm"];
            $output=array();
            exec("./la $s1 $s2 $s1l $s2l $gp $m $mm ",$output);
            foreach($output as $line)
            {
                echo("<div id='line'>$line</div>");
            
            }     
        ?>
    </div>
</body>
</html>