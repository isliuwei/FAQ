var express = require('express');
var router = express.Router();





var DevArr = [];
var ColArr = [];
var ChaArr = [];

DevArr = [
  {
    devName: 'Keyboard',
    devType: 'I',
    Status: '0',
    devCol: 'CO1',
    devQue:[]
  },
  {
    devName: 'Mouse',
    devType: 'I',
    Status: '0',
    devCol: 'CO1',
    devQue:[]
  },
  {
    devName: 'Display',
    devType: 'O',
    Status: '0',
    devCol: 'CO2',
    devQue:[]
  },
  {
    devName: 'Printer',
    devType: 'O',
    Status: '0',
    devCol: 'CO3',
    devQue:[]
  }
];


ColArr = [
  {
    colName: 'CO1',
    Status: '0',
    colCha: 'CH1',
    colQue: []
  },
  {
    colName: 'CO2',
    Status: '0',
    colCha: 'CH2',
    colQue: []
  },
  {
    colName: 'CO3',
    Status: '0',
    colCha: 'CH2',
    colQue: []
  }
];


ChaArr = [
  {
    chaName: 'CH1',
    Status: '0',
    chaQue: []
  },
  {
    chaName: 'CH2',
    Status: '0',
    chaQue: []
  }

];

//var addDev = function(){
//
//};


var isCol = function(devCol,ColArr){
  var bFlag = 0;
  for(var i=0; i<ColArr.length; i++){
    if(ColArr[i].colName == devCol){
      bFlag = 1;
      break;
    }else{
      bFlag = 0;
    }
  }
  return bFlag;
};

var devIndex = function(devName){
  for(var i=0; i<DevArr.length; i++){
    if(DevArr[i].devName == devName){
      return i;
    }
  }
};

var colIndex = function(colName){
  for(var i=0; i<ColArr.length; i++){
    if(ColArr[i].colName == colName){
      return i;
    }
  }
};

var getDevObj = function(devName){
  for(var i=0; i<DevArr.length; i++){
    if(DevArr[i].devName == devName){
      return DevArr[i];
    }
  }
};


var getColObj = function(devName){
  var devObj = getDevObj(devName);
  var colName = devObj.devCol;
  for(var i=0; i<ColArr.length; i++){
    if(ColArr[i].colName == colName){
      return ColArr[i];
    }
  }

};

var getChaObj = function(devName){
  var colObj = getColObj(devName);
  var chaName = colObj.colCha;
  for(var i=0; i<ChaArr.length; i++){
    if(ChaArr[i].chaName == chaName){
      return ChaArr[i];
    }
  }


};

/*
var isBusy = function(itemArr){
  var bFlag = 0;
  for(var i=0; i<itemArr.length; i++){
    if(itemArr[i].Status == 1){
      bFlag = 1;
      break;
    }else{
      bFlag = 0;
    }
  }
  return bFlag;

};
*/
var isBusy = function(itemObj){

  var bFlag = 0;
  bFlag = itemObj.Status == '1'?1:0;
  return bFlag;

};












/* GET home page. */
router.get('/', function(req, res) {
  res.render('index',{
    DevArr: DevArr,
    ColArr: ColArr,
    ChaArr: ChaArr
  });
});


router.get('/checkCol', function(req, res) {
  var devCol = req.query.devCol;

  if(isCol(devCol,ColArr)){
    res.send('success');
  }else{
    res.send('fail');
  }

});



router.post('/addDev', function(req, res) {
  var devName = req.body.devName;
  var devType = req.body.devType;
  var devCol = req.body.devCol;


  if(isCol(devCol,ColArr)){

    DevArr.push({
      devName: devName,
      devType: devType,
      Status: '0',
      devCol: devCol,
      devQue: []
    });

    res.redirect(303,'/');



  }else{


    var colCha = req.body.colCha;
    DevArr.push({
      devName: devName,
      devType: devType,
      Status: '0',
      devCol: devCol,
      devQue: []
    });

    ColArr.push({
      colName: devCol,
      Status: '0',
      colCha: colCha,
      colQue: []

    });

    res.redirect(303,'/');



  }



});







router.post('/delDev',function(req,res){

  var devName = req.body.devName;
  var colObj = getColObj(devName);

  DevArr.splice(devIndex(devName),1);

  ColArr.splice(colIndex(colObj.colName),1);

  res.redirect(303,'/');
});


router.post('/appDev',function(req,res){
  var procName = req.body.procName;
  var devName = req.body.devName;
  var devObj = getDevObj(devName);
  var colObj = getColObj(devName);
  var chaObj = getChaObj(devName);

  if(isBusy(devObj)){
    devObj.devQue.push(procName);
  }else{
    devObj.Status = '1';
    if(isBusy(colObj)){
      colObj.colQue.push(procName);
    }else{
      colObj.Status = '1';
      //devObj.devQue.push(procName);
      if(isBusy(chaObj)){
        chaObj.chaQue.push(procName);
      }else{
        chaObj.Status = '1';
        devObj.devQue.push(procName);
      }
    }
    //devObj.devQue.push(procName);

  }

  res.redirect(303,'/');


});


router.post('/relDev',function(req,res){
  var devName = req.body.devName;
  var devObj = getDevObj(devName);
  var colObj = getColObj(devName);
  var chaObj = getChaObj(devName);


  var devQueArr = devObj.devQue;
  var colQueArr = colObj.colQue;
  var chaQueArr = chaObj.chaQue;


  if(devQueArr.length>0){
    devQueArr.shift();
    if(devQueArr.length == 0){
      devObj.Status = '0';
      colObj.Status = '0';
      chaObj.Status = '0';
    }
  }

  if(colQueArr.length>0){
    colQueArr.shift();
    if(colQueArr.length == 0){
      colObj.Status = '0';
      //devObj.Status = '0';
    }
  }

  if(chaQueArr.length>0){
    chaQueArr.shift();
    if(chaQueArr.length == 0){
      chaObj.Status = '0';
    }
  }


  /*
  if(devObj.devQue.length>0){
    devObj.devQue.shift();
    if(devObj.devQue.length==0){
      devObj.Status = '0';
      colObj.Status = '0';
      chaObj.Status = '0';
    }

  }else{
    if(devObj.devQue.length==0){
      devObj.Status = '0';
    }
  }

  if(colObj.colQue.length>0){
    colObj.colQue.shift();
    if(colObj.colQue.length==0){
      colObj.Status = '0';
    }

  }

  if(chaObj.chaQue.length>0){
    chaObj.chaQue.shift();
    if(chaObj.chaQue.length==0){
      chaObj.Status = '0';
    }

  }*/

  res.redirect(303,'/');


});





module.exports = router;
