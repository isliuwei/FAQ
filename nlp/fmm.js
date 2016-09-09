var lunr = require("./lunr.js");
var idxdata = require("./idx.json");

var idx = lunr.Index.load(idxdata);
var ii = idx.tokenStore;
//console.log(ii.root)

var query1 = "中国人民银行指出我国最近经济不景气";
var query2 = "习近平今日出席了中央气象台的联欢晚会";
var query3 = "中国银行今日出台了最新的贷款政策"
var query5 = "全部门";
var query6 = "互联网金宝中央气象台";
var query7 = "上下级别";
var query8 = "确定期";
var query9 = "引领土完整";

query = query6;
var result = tokenizer(ii.root, query);
console.log(result);

function tokenizer(root, str) {
  if (root == null || root == undefined) return [];
  if (str == null || str == undefined || str.length == 0) return [];

  var out = [];
  while (str.length > 0) {
    var word = matchLongest(root, str);
    out.push(word);
    str = str.slice(word.length);
  }

  return out;
}

function matchLongest(root, str) {
  if ( root == null || root == undefined ) return;
  if ( str == null || str == undefined || str.length == 0 ) return;

  var maxMatch = "";
  var currentNode = root;
  for( var i = 0; i < str.length; i++ ) {
    if (str[i] in currentNode ) {
      maxMatch += str[i];
      currentNode = currentNode[str[i]];
    } else {
      if ( maxMatch.length == 0 ) maxMatch = str[i];
      break;
    }
  }

  return maxMatch;
}

function getAmbiguiousLength(root, str, word_length) {
  var i = 1
  while ( i < word_length && i < str.length ) {
    var wid = tokenize(root, str.slice(i))
    wid = wid[0];
    var length = wid.length;
    if ( word_length < i + length ) word_length = i + length;
    //console.log("i = " + i  + ",length=" + wid.length + ", wid :" + wid + ", word_length : " + word_length)
    i += 1;
  }

  return word_length;
}