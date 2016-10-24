<?php
$aderInfo = $this -> session -> userdata('aderInfo');
if(!$aderInfo){
redirect('welcome/index');
}
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <base href="<?php echo site_url(); ?>">
    <!-- <link rel="shortcut icon" href="img/logo.jpeg"/> -->
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <link rel="stylesheet" href="css/font-awesome.min.css">
    <link rel="stylesheet" href="css/ader-index.css">
    <link rel="stylesheet" href="css/ader-index-xin.css">
    <title>慧播网  广告主主页</title>
  </head>
  <body>
    
    <header class='navbar navbar-default navbar-fixed-top' id='main-navbar' role='banner'>
      <div class='container-fluid'>
        <div class='navbar-header'>
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".navbar-collapse">
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          </button>
          
        </div>
        <nav class='collapse navbar-collapse' role='navigation'>
          <ul class='nav navbar-nav navbar-left'>
            <li><a href="welcome/index"><i class="fa fa-home"></i> 首页</a></li>
            <li><a href="ader/ader_index"><i class="fa fa-at"></i> <?php echo $aderInfo -> ader_companyName ; ?></a></li>
            <li class="active"><a class="forbid" href="javascript:;"><i class="fa fa-dashboard"></i> 管理页面</a></li>
          </ul>
          <div class="center-block label labe-tel"><i class="fa fa-phone"></i> <a class="a-tel" href="tel:01085954789">合作咨询：010-85954789</a></div>
          <ul class='nav navbar-nav navbar-right'>
            <a class="btn btn-success navbar-btn login-btn"  href="ader/anchor_need_profile">需求管理</a>
            <a class="btn btn-primary navbar-btn login-btn"  href="ader/ader_setting?ader_id=<?php echo  $aderInfo -> ader_id ;?>">账号管理</a>
            <a class="btn btn-default navbar-btn login-btn" href="ader/logout">退出登录</a>
            <a class="btn navbar-btn js-login-btn" href="#">Register</a>
          </ul>
        </nav>
      </div>
    </header>
  
    <div id="content">
      <div class="container">
        <ul id="lists">
         <!--  <li  class="col-xs-6 col-md-4" >  <a href="ader/anchor"><div class="img" style="background: url(img/ader-index-1.jpg); background-size:100% 100% ;"></div><div class="button">平台主播资源</div></a></li>
          <li  class="col-xs-6 col-md-4" >  <a href="ader/slogan"><div class="img" style="background: url(img/ader-index-2.jpg); background-size:100% 100% ;"></div><div class="button">直播内容策划服务</div></a></li>
          <li  class="col-xs-6 col-md-4" >  <a href="ader/anchor_need"><div class="img" style="background: url(img/ader-index-3.jpg); background-size:100% 100% ;"></div><div class="button">发布主播需求</div></a></li>
          <li  class="col-xs-6 col-md-4" > <a href="company/company_list"> <div class="img" style="background: url(img/ader-index-4.jpg); background-size:100% 100% ;"></div><div class="button">媒体资源服务</div></a></li>
          <li  class="col-xs-6 col-md-4" > <a href="ader/company_slogan"> <div class="img" style="background: url(img/ader-index-5.jpg); background-size:100% 100% ;"></div><div class="button">媒体资源投放策略服务</div></a></li>
          <li  class="col-xs-6 col-md-4" > <a href="ader/company_need"> <div class="img" style="background: url(img/ader-index-6.jpg); background-size:100% 100% ;"></div><div class="button">发布媒体资源需求</div></a></li> -->


        <?php
          foreach ($aderImages as $img) {
           
        ?>

          <li  class="col-xs-6 col-md-4" >  <a href="<?php echo $img -> aderFun_href ;?>"><div class="img" style="background: url(<?php echo $img -> aderImage_url ;?>); background-size:100% 100% ;"></div><div class="button"><?php echo $img -> aderImage_name ;?></div></a></li>

        <?php
          }
        ?>

          
          
        </ul>
      </div>
    </div>
    <script src="js/jquery-1.11.3.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>