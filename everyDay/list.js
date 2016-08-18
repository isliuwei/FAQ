function List()
{
  this.listSize = 0;
  this.pos = 0;
  this.length = length;
  this.dataStore = [];
  this.append = append;
  this.find = find;
  this.remove = remove;
  this.toString = toString;
  this.insert = insert;
  this.clear = clear;
  this.contains = contains;
  this.front = front;
  this.end = end;
  this.prev = prev;
  this.next = next;
  this.currPos = currPos;
  this.moveTo = moveTo;
  this.getElement = getElement;
}


function length(){
  return this.listSize;
}

function append(element){
  this.dataStore[this.listSize++] = element;
}

function find(element){
  for(var i = 0; i < this.dataStore.length; i++){
    if(this.dataStore[i] === element){
      return i;
    }
  }
  return -1;
}

function remove(element){
  var foundAt = this.find(element);
  if(foundAt > -1){
    this.dataStore.splice(foundAt,1);
    return true;
  }
  return false;
}

function toString() {
  return this.dataStore;
}

function insert(element, after){
  var insertPos = this.find(after);
  if( insertPos > -1 ){
    this.dataStore.splice(insertPos+1, 0, element);
    ++this.listSize;
    return true;
  }
  return false;
}

function clear() {
	    delete this.dataStore;
	    this.dataStore = [];
	    this.listSize = this.pos = 0;
}

function contains(element){
  for( var i = 0; i < this.dataStore.length; i++){
    if( this.dataStore[i] === element){
      return true;
    }
  }
  return false;
}

function front() {
  this.pos = 0;
}
function end() {
   this.pos = this.listSize-1;
}
function prev() {
   if (this.pos > 0) {
      --this.pos;
   }
}
function next() {
   if (this.pos < this.listSize-1) {
      ++this.pos;
   }
}
function currPos() {
   return this.pos;
}
function moveTo(position) {
   this.pos = position;
}
function getElement() {
   return this.dataStore[this.pos];
}







var clist = new List();
clist.append("zhangsan");
clist.append("lisi");
clist.append("wangwu");
clist.append("liudehua");
clist.append("zhangxueyou");
console.log(clist.toString());
console.log(clist.length());
console.log(clist.find("lisi"));
console.log(clist.remove("wangwu"));
console.log(clist.toString());
console.log(clist.length());
clist.insert("zhaoliu","lisi");
console.log(clist.length());
console.log(clist.toString());
console.log(clist.contains("zhaoliu"));
console.log(clist.contains("zhoujielun"));
clist.front();
console.log(clist.getElement());
clist.next();
console.log(clist.getElement());
clist.next();
clist.next();
clist.prev();
clist.prev();
clist.prev();
console.log(clist.getElement());
clist.clear();
console.log(clist.length());
console.log(clist.toString());
