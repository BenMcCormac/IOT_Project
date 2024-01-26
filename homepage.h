// To create literal strings stored in flash memory enclose your HTML code between 
// F(R"=====( HTML code here )=====");
// If you have 1 reading then you probably have 2 literal strings
// If you have 2 readings then you probably have 3 literal strings etc.

String homePagePart1 = F(R"=====(<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, viewport-fit=cover">
  <title>Demo Website</title>

  <style>
    *{
      margin:0px;
      padding:0px;
      font-family: Arial, Helvetica, sans-serif;
      box-sizing: border-box;
      }
    body {       
      background-color:blanchedalmond;
    }
    .flex-Container{
      display: flex;
      flex-direction: column;
      background-color:blanchedalmond;
      align-items: center;
    }
    #Sidebar{
      width: 400px;
      height: 982px;
      float: left;
      background-color:yellow;
      min-height: 400px;
      text-align: center;
    }
    #Text{
      text-align: center;
      float: left;
    }
    h1{
      font: bold;
      font-size: 40px;                    
      color: rgb(7, 6, 2);
      text-align: center;
    }
    hr{
      color:rgb(100, 100, 50);
    }
    p{
      font-size: 28px;
      color: rgb(0, 0, 0);
    }
    th, td {
      font-size: 25px;
      padding: 8px;
      text-align: left;
      border-bottom: 1px solid #ddd;
    }
  </style>
</head>
<body>
    <div id="Head">
        <h1>IOT Apiary</h1>
    </div>
    <hr>

    <div id="Sidebar">
        <h3>Apiary #1</h3>

        <p>This is where all the information from the sensors will show up<br></p>
        <p>A table will appear below here<br><br></p>

        <table>
            <tr>
                <th>Sensor</th>
                <th>Value</th>
                <th>Unit</th>
            </tr>
            <tr>
                <td>Temperature</td>
                <td>)=====");
String homePagePart2 = F(R"=====(</td>
                <td>Degree Celsius</td>
            </tr>
            <tr>
                <td>Humidity</td>
                <td>)=====");
String homePagePart3 = F(R"=====(</td>
                <td>Percent</td>
            </tr>
            <tr>
                <td>Light</td>
                <td><i>Yes or No (threshold). Sample No.</i></td>
                <td>Lumens</td>
            </tr> 
        </table>

        <hr>

        <p>Status of the lid (Open or Closed)</p>
        <p><i>Button for the Lock</i></p>

        <hr>

        <p><i>Button that activates the CO2 pump</i></p>

        <hr>

        <p>Comb Division status<br>(Using the preassure sensors)</p>
        <br>
        <p>Comb Div #1 (In/Out)</p>
        <p>Comb Div #2 (In/Out)</p>
        <p>Comb Div #3 (In/Out)</p>
    </div>
    <div id="Text">
        <p>There will be multiple Sections for multiple apiaries</p>
    </div>
</body>
</html>)=====");
