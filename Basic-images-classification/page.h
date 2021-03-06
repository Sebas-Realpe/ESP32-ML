static const char page[] = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
 
 <head>
   <meta charset="UTF-8">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>ESP32-CAM TensorflowJS</title>
   <style>
   body {
   font-family: "PT Sans", sans-serif;
   background-color: #dde2e1;
   margin: 0;
   color: #636060;
   line-height: 1.6;
   }
   a {
   text-decoration: none;
   color: #ccc;
   }
   h2 {
   display: block;
   font-size: 1.17em;
   margin-block-start: 1em;
   margin-block-end: 1em;
   margin-inline-start: 0px;
   margin-inline-end: 0px;
   font-weight: bold;
   }
   .container {
   max-width: 1180px;
   text-align: center;
   margin: 0 auto;
   padding: 0 3rem;
   }
   .btn {
   padding: 1rem;
   color: #fff;
   display: inline-block;
   background: red;
   margin-bottom: 1rem;
   }
 
   </style>
   <script src="https://cdn.jsdelivr.net/npm/@tensorflow/tfjs"> </script>
    <script src="https://cdn.jsdelivr.net/npm/@tensorflow-models/mobilenet"> </script>
 
    <script language="javascript">
        function classifyImg() {
           const img = document.getElementById("img1");
           const r = document.getElementById("results");
           r.innerHTML = "";
 
           console.log("Classify...");
           img.crossorigin = " ";
           img.onload = function() {
                console.log("Wait to load..");
                mobilenet.load().then(model => {
                // Classify the image.
                model.classify(img).then(predictions => {
                  for (i in predictions) {
                    r.innerHTML = r.innerHTML + "<b>" + predictions[i].className + "</b> - " + predictions[i].probability + "<br/>";
                    img.onload = null;
                    img.src = "http://192.168.1.119:81";
                  }
                });
               });
           }
           img.src = "http://192.168.1.119/capture?t=" + Math.random();
        }
    </script>
   </head>
 
   <body>
     <div class="container">
     <h2>TensorflowJS with ESP32-CAM</h2>
     <section>
       <img id="img1" width="320" height="200" src="http://192.168.1.119:81" crossorigin style="border:1px solid red"/>
       <div id="results"/>
     </section>
     <section>
       <a href="#" class="btn" onclick="classifyImg()">Classify the image</a>
      </section>
      <section id="i" />
   </div>
   </body>
</html>
)rawliteral";
