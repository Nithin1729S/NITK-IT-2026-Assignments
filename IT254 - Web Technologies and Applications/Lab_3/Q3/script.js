var testScore = {
    name: "",
    math: 0,
    physics: 0,
    chemistry: 0,
    avg: 0
  };
  var i = 1;
  
  function score_table() {
    document.getElementById("divTable").style.display = "block";
  
    
    testScore.name = document.getElementById("name").value;
    testScore.rollno = document.getElementById("rollno").value;
    testScore.branch = document.getElementById("branch").value;
    testScore.email = document.getElementById("email").value;
    document.getElementById("name").value = "";
    document.getElementById("rollno").value = "";
    document.getElementById("branch").value = "";
    document.getElementById("email").value = "";
  
    
    var table = document.getElementById("tableScore");
    var row = table.insertRow(i);
    var number = row.insertCell(0);
    var name = row.insertCell(1);
    var rollno = row.insertCell(2);
    var branch = row.insertCell(3);
    var email = row.insertCell(4);
  
    number.innerHTML = i;
    name.innerHTML = testScore.name;
    rollno.innerHTML = testScore.rollno;
    branch.innerHTML = testScore.branch;
    email.innerHTML = testScore.email;
   
    i++;
    
  }
  
  
  
