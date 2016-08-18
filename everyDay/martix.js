/*

Array.martix = function(row,col,init){
    var arr = [];
    for(var i=0; i<row; i++){
      var colArr = [];
      for(var j=0; j<col; j++){
        colArr[j] = init;
      }
      arr[i] = colArr;
    }
    return arr;
  }

  console.log(Array.martix(5,5,0));
*/

/*
var grades = [[90,78,65,49],[99,87,57,79],[100,38,85,49],[89,67,86,59]];
  var total = 0;
  var average = 0;
  for( var row=0; row<grades.length; row++ ){
      for( var col=0; col<grades[row].length; col++){
        total+=grades[row][col];
      }
    console.log("学生"+(row+1)+" average:"+total/grades[row].length);
    total = 0;
    average = 0;
  }
  */


  Array.martix = function(row,col,init){
      var arr = [];
      for(var i=0; i<row; i++){
        var colArr = [];
        for(var j=0; j<col; j++){
          colArr[j] = init;
        }
        arr[i] = colArr;
      }
      return arr;
    }

var arr = Array.martix(5,5,5);

//var newArr = arr.concat.apply([],arr);
//var newArr = Array.prototype.concat.apply([],arr);
var newArr = [].contact.apply([],arr);
console.log(newArr);
