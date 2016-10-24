<!DOCTYPE html>
<html lang="en" ng-app="myApp" ng-controller="FormController">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    
    <title>慧播网</title>
    <base href="<?php echo site_url(); ?>">
    <!-- <link rel="shortcut icon" href="img/logo.jpeg"/> -->
    <link rel="stylesheet" href="css/bootstrap.min.css" />
    <link rel="stylesheet" href="css/index-xin.css">
    <link rel="stylesheet" href="css/contact.css" />
    <link rel="stylesheet" href="css/index.css" />
    <link rel="stylesheet" href="css/font-awesome.min.css" />
    <!-- <link rel="stylesheet" href="css/lrtk.css" /> -->
    <!-- <link rel="stylesheet" href="css/btn.css" /> -->
  </head>
  <body>
    <header id="header">
      <nav class="navbar navbar-inverse navbar-fixed-top" id="nav">
        <div class="container">
          <div class="navbar-header">
            <button class="navbar-toggle" data-toggle="collapse" data-target="#responsive-navbar">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            </button>
            <a href="#" class="navbar-brand">
              <strong>LOGO</strong>
              <div class="line"></div>
              慧播网
            </a>
          </div>
          <div class="collapse navbar-collapse" id="responsive-navbar">
            
            <div class="profile">
              <ul class="nav navbar-nav main">
                <li><a href="welcome/index">首页</a></li>
                <li class="hidden-xs"><div class="line line2"></div></li>
                <li><a href="" >联系我们</a></li>
              </ul>
              <a class="tel" href="tel:01085954789">合作咨询:01085954789</a>
            </div>
            
          </div>
        </div>
      </nav>
    </header>
    <div class="modal fade" id="contact-form" tabindex="-1" role="dialog">
      <div class="modal-dialog" role="document">
        <button type="button" class="close"  data-dismiss="modal" aria-label="Close"><span aria-hidden="true" style="font-size: 50px; color: white ;">&times;</span></button>
        <div id="wrap">
          <h1>了解更多</h1>
          <div id='form_wrap'>
            <form class="contact-form">
              <label class="contact-label" for="message"><i class="fa fa-map"></i> 地址: </label>
              <textarea class="textarea-field"  disabled>北京市朝阳区建国门外大街店甲12号新华保险大厦A座15层</textarea>
              <label class="contact-label" for="name"><i class="fa fa-phone"></i> 电话: </label>
              <input class="text-input" value="010-85954789" disabled/>
              <label class="contact-label" for="email"><i class="fa fa-envelope"></i> 邮箱: </label>
              <input class="text-input"  value="feelings_admcl@126.com" disabled/>
            </form>
          </div>
        </div>
      </div>
    </div>
    
    
    <div id="carousel">
      
      <div class="carousel slide" data-ride="carousel" id="slideshow" data-interval="2000" data-pause="false">
        <ol class="carousel-indicators">
          
         <!--  <li data-target="#slideshow" data-slide-to="1"></li>
          <li data-target="#slideshow" data-slide-to="2"></li> -->




          <?php 
            foreach ($carousel as $car) {
          ?>


          <li data-target="#slideshow" data-slide-to="<?php echo ($car -> carousel_id - 1)?>"  class="<?php echo $car->carousel_id==1?"active":"" ?>"></li>



           
          <?php 
            }
          ?>







        </ol>
        
        <div class="carousel-inner">
          
          <?php 
            foreach ($carousel as $car) {
          ?>
            <div class="item <?php echo $car->carousel_id==1?"active":"" ?>">
                <img src="<?php echo $car -> carousel_url?>" class="a" title="<?php echo $car -> carousel_name?>"  alt="<?php echo $car -> carousel_name?>">
            </div> 
          <?php 
            }
          ?>








        </div>
      </div>
      <div class="carousel-caption">
        <h2>选择最合适.最快速.最便捷的方式</h2>
        <hr>
        <h1>为您服务</h1>
        <a href="" class="pointer"  data-toggle="modal" data-target="#contact-form" >了解更多</a>
      </div>
    </div>
    
    <div id="logins">
      <h1 class="title">请选择适合您的登陆窗口</h1>
      <span  class="Check"> Check In The Login Window</span>
      <div class="container">
        
        <!-- <div class="login1" style="background: url(img/login-1.jpg);background-size:100% 100%;">
          
          <a  href="#" class=""  data-toggle="modal" data-target="#ader-reg" style="display: inline-block; width: 100%;height: 100%;">
            <div class="window">
              <h1>广告主登录窗口</h1>
              <p>Advertisers Login Window</p>
            </div>
         
          <div class="mark"></div> </a>
        </div> -->


        <?php
            $ii = 0;
          foreach ($loginImage as $img) {
            $ii++;
          
        ?>



        <div class="login<?php echo $ii ;?>" style="background: url(<?php echo $img -> loginImage_url ;?>);background-size:100% 100%;">
          
          <a  href="#" class=""  data-toggle="modal" data-target="#<?php echo $img -> loginImage_href ;?>" style="display: inline-block; width: 100%;height: 100%;">
            <div class="window">
              <h1><?php echo $img -> loginImage_name ;?></h1>
              <p><?php echo $img -> loginImage_desc ;?></p>
            </div>
         
          <div class="mark"></div> </a>
        </div>







        <?php
          }
        ?>










        <!-- <div class="login2" style="background: url(img/login-2.jpg);background-size:100% 100%;">
          <div class="mark"></div>
          <a   data-toggle="modal" data-target="#anchor-reg" style="display: inline-block; width: 100%;height: 100%;">
            <div class="window">
              <h1>主播登录窗口</h1>
              <p>Advertisers Login Window</p>
            </div>
          </a>
        </div>
        <div class="login3" style="background: url(img/login-3.jpg);  background-size:100% 100%;">
          <div class="mark"></div>
          <a  href="#"  data-toggle="modal" data-target="#company-reg" style="display: inline-block; width: 100%;height: 100%;">
            <div class="window">
              <h1>媒体公司登录窗口</h1>
              <p>Advertisers Login Window</p>
            </div>
          </a>
        </div> -->
        <span class="arrow arrow-left " ></span>
        <span class="arrow arrow-right"></span>
      </div>
    </div>
    <div class="modal fade in" id="ader-reg" tabindex="-1" >
      <div class="modal-dialog">
        <form action="ader/check_login" method="post" class="loginform" name="aderForm">
          <div class="modal-content" id="login-content">
            <div class="modal-header" id="login-title">
              <button class="close" data-dismiss="modal">&times;</button>
              <h3>广告主登录</h3>
            </div>
            <div class="modal-body" id="login-body">
              <div class="pad">
                <input type="hidden" name="" value="">
                <div class="control-group">
                  <div class="controls">
                    <input id="center"
                      ng-model="aderInfo.aderUsername"
                      id="ader-username"
                      type="text"
                      name="aderUsername"
                      placeholder="用户名"
                      tabindex="1"  class="form-control input-medium"
                      ng-class="{
                      'error': aderForm.aderUsername.$invalid && aderForm.aderUsername.$touched,
                      'success':aderForm.aderUsername.$valid }"
                      required
                    >
                    

                   
                  </div>
                </div>
                <div class="control-group">
                  <div class="controls">
                    <input id="center"
                      ng-model="aderInfo.aderPassword"
                      id="ader-password"
                      type="password"
                      name="password"
                      placeholder="密码"
                      tabindex="2" class="form-control input-medium"
                      ng-class="{
                      'error': aderForm.password.$invalid && aderForm.password.$touched,
                      'success':aderForm.password.$valid }"
                      required
                    >
                  </div>
                </div>
                <div class="control-group">
                  <div class="controls">
                    <div class="a">
                      <input
                        ng-model="aderInfo.aderCaptcha"
                        id="ader-captcha"
                        type="number"
                        name="aderCaptcha"
                        placeholder="验证码" tabindex="2"
                        class="form-control col-md-2 captcha"
                        ng-class="{
                        'error': aderForm.aderCaptcha.$invalid && aderForm.aderCaptcha.$touched,
                        'success':aderForm.aderCaptcha.$valid }"
                        required
                        compare="loginInfo.captcha_ci"
                        style="  margin-right:10px; margin-bottom: 10px;display: inline-block;"
                      >
                      
                      <input
                        type="hidden"
                        ng-model="loginInfo.captcha_ci"
                        name="captcha_ci"
                        class="captcha_ci"
                      >
                      
                      
                      <img class="captcha-img" id="ader-captcha-img" src="captcha/<?php echo $codeinfo['time']; ?>.jpg" alt="">
                      <span id="captcha-tip" class="captcha-tip change" >  <i class="fa fa-refresh"></i>换一换</span>
                     <!--  <span
                        class="error-info"
                        ng-if="aderForm.aderCaptcha.$error.compare && aderForm.aderCaptcha.$touched">
                      验证码输入错误</span> -->
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div class="modal-footer">
              <div class="form-actions">
                <p><a href="javascript:;" tabindex="5" class="pull-left btn-link text-muted" data-toggle="tooltip" data-placement="left" title="修改密码，请您拨打客服电话！">忘记密码?</a></p>
                <br>
                <button type="submit" tabindex="4" class="btn btn-primary modal-btn" ng-disabled="aderForm.$invalid">登录</button>
                <button type="button" tabindex="4" class="btn btn-warning modal-btn"><a href="ader/ader_reg" style="display:block;color:#fff;">注册</a></button>
              </div>
            </div>
          </div>
        </form>
      </div>
    </div>
    <div class="modal fade in" id="anchor-reg" tabindex="-1" >
      <div class="modal-dialog">
        <form action="anchor/check_login" method="post" class=" loginform" name="anchorForm" >
          <div class="modal-content" id="login-content">
            <div class="modal-header" id="login-title">
              <button class="close" data-dismiss="modal">&times;</button>
              <h3>主播登录</h3>
            </div>
            <div class="modal-body" id="login-body">
              <div class="pad">
                <input type="hidden" name="" value="">
                <div class="control-group">
                  <div class="controls">
                    <input id="center"
                        ng-model="anchorInfo.anchorUsername"
                        name="anchorUsername"
                        id="anchor-username"
                        type="text"
                        placeholder="用户名" tabindex="1"  class="form-control input-medium"
                        ng-class="{
                        'error': anchorForm.anchorUsername.$invalid && anchorForm.anchorUsername.$touched,
                        'success':anchorForm.anchorUsername.$valid }"
                        required
                    >

                    
                  </div>
                </div>
                <div class="control-group">
                  <div class="controls">
                    <input id="center"
                      ng-model="anchorInfo.anchorPassword"
                      name="anchorPassword"
                      id="anchor-password"
                      type="password"
                      placeholder="密码" tabindex="2" class="form-control input-medium"
                      ng-class="{
                      'error': anchorForm.anchorPassword.$invalid && anchorForm.anchorPassword.$touched,
                      'success':anchorForm.anchorPassword.$valid }"
                      required
                    >
                  </div>
                </div>
                <div class="control-group">
                  <div class="controls">
                    <div class="a">
                      <input
                        ng-model="anchorInfo.anchorCaptcha"
                        name="anchorCaptcha"
                        id="anchor-captcha"
                        type="number"
                        placeholder="验证码" tabindex="2" class="form-control col-md-2 captcha"
                        ng-class="{
                        'error': anchorForm.anchorCaptcha.$invalid && anchorForm.anchorCaptcha.$touched,
                        'success':anchorForm.anchorCaptcha.$valid }"
                        required
                        compare="loginInfo.captcha_ci"
                        style="  margin-right:10px; margin-bottom: 10px;display: inline-block"
                      >
                      
                      <input
                        type="hidden"
                        ng-model="loginInfo.captcha_ci"
                        name="captcha_ci"
                        class="captcha_ci"
                      >
                      
                      <img class="captcha-img" id="anchor-captcha-img" src="captcha/<?php echo $codeinfo['time']; ?>.jpg" alt="">
                      <span id="captcha-tip" class="captcha-tip change"> <i class="fa fa-refresh"></i> 换一换</span>
                     <!--  <span
                        class="error-info"
                        ng-if="aderForm.aderCaptcha.$error.compare && aderForm.aderCaptcha.$touched">
                      验证码输入错误</span> -->
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div class="modal-footer">
              <div class="form-actions">
                <p><a href="javascript:;" tabindex="5" class="pull-left btn-link text-muted" data-toggle="tooltip" data-placement="left" title="修改密码，请您拨打客服电话！">忘记密码?</a></p>
                <br>
                <button type="submit" tabindex="4" class="btn btn-primary modal-btn" ng-disabled="anchorForm.$invalid">登录</button>
                <button type="button" tabindex="4" class="btn btn-warning modal-btn"><a href="anchor/anchor_reg" style="display:block;color:#fff;">注册</a></button>
              </div>
            </div>
          </div>
        </form>
      </div>
    </div>
    <div class="modal fade in" id="company-reg"  tabindex="-1" >
      <div class="modal-dialog">
        <form action="company/check_login" method="post" class=" loginform" name="companyForm" >
          <div class="modal-content" id="login-content">
            <div class="modal-header" id="login-title">
              <button class="close" data-dismiss="modal">&times;</button>
              <h3>媒体资源公司登录</h3>
            </div>
            <div class="modal-body" id="login-body">
              
              <div class="pad">
                <input type="hidden" name="" value="">
                <div class="control-group">
                  <div class="controls">
                    <input id="center"
                      ng-model="companyInfo.companyUsername"
                      name="companyUsername"
                      id="company-username"
                      type="text"
                      placeholder="用户名" tabindex="1"  class="form-control input-medium"
                      ng-class="{
                      'error': companyForm.companyUsername.$invalid && companyForm.companyUsername.$touched,
                      'success':companyForm.companyUsername.$valid }"
                      required
                    >
                  </div>
                </div>
                <div class="control-group">
                  <div class="controls">
                    <input id="center"
                      ng-model="companyInfo.companyPassword"
                      name="companyPassword"
                      id="company-password"
                      type="password"
                      placeholder="密码" tabindex="2" class="form-control input-medium"
                      ng-class="{
                      'error': companyForm.companyPassword.$invalid && companyForm.companyPassword.$touched,
                      'success':companyForm.companyPassword.$valid }"
                      required
                    >
                  </div>
                </div>
                <div class="control-group">
                  <div class="controls">
                    <div class="a">
                      <input
                        ng-model="companyInfo.companyCaptcha"
                        name="companyCaptcha"
                        id="company-captcha"
                        type="number"
                        placeholder="验证码" tabindex="2" class="form-control col-md-2 captcha"
                        ng-class="{
                        'error': companyForm.companyCaptcha.$invalid && companyForm.companyCaptcha.$touched,
                        'success':companyForm.companyCaptcha.$valid }"
                        required
                        compare="loginInfo.captcha_ci"
                        style="  margin-right:20px; margin-bottom: 10px;display: inline-block"
                      >
                      
                      <input
                        type="hidden"
                        ng-model="loginInfo.captcha_ci"
                        name="captcha_ci"
                        class="captcha_ci"
                      >
                      
                      <img class="captcha-img" id="company-captcha-img" src="captcha/<?php echo $codeinfo['time']; ?>.jpg" alt="">
                      <span id="captcha-tip" class="captcha-tip change">  <i class="fa fa-refresh"></i>换一换</span>
                     <!--  <span
                        class="error-info"
                        ng-if="aderForm.aderCaptcha.$error.compare && aderForm.aderCaptcha.$touched">
                      验证码输入错误</span> -->
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div class="modal-footer">
              <div class="form-actions">
                <p><a href="javascript:;" tabindex="5" class="pull-left btn-link text-muted" data-toggle="tooltip" data-placement="left" title="修改密码，请您拨打客服电话！">忘记密码?</a></p>
                <br>
                <button type="submit" tabindex="4" class="btn btn-primary modal-btn" ng-disabled="companyForm.$invalid">登录</button>
                <button type="button" tabindex="4" class="btn btn-warning modal-btn"><a href="company/company_reg" style="display:block;color:#fff;">注册</a></button>
              </div>
            </div>
          </div>
        </form>
      </div>
    </div>
    
    
    <div id="use">
      <h1>平台使用守则</h1>
      <span>Platform Usage Instructions</span>
      <div class="container">
        <div class="row">
          <div class="col-md-4" id="row">
            <div class="icons icon1"></div>
            <h4>你是广告主</h4>
            <p>不论您是需要直播领域的任何相关服务
              还是传统媒介的任何相关服务，请您点击广告主吧
              平台将为您提供最透明的价格，最匹配的资源,
              最高效的运作彻底为您解决资源渠道不匹配，
              价格掺水不透明，执行效率低下的问题。
            </p>
          </div>
          <div class="col-md-4" id="row">
            <div class="icons icon2"></div>
            <h4>你是主播</h4>
            <p>不论   您是个人主播，还是工会主播，
              不论您是哪个直播平台的主播，
              只要您相信自己，相信平台，
              那么就点击主播吧，
              我们将为您重新定义主播的价值。
            </p>
          </div>
          <div class="col-md-4" id="row">
            <div class="icons icon3"></div>
            <h4>你是媒体资源公司</h4>
            <p>如果您是媒体资源公司，或媒介平台，
              只要您是一手资源，并相信您的价值，
              那么就请您点击媒体公司吧，
              在这里，我们将为您重新定义您的资源
              所具备的真正价值。
            </p>
            
          </div>
        </div>
      </div>
    </div>
    <div id="profile">
      <div class="container">
        <center><h1>平台案例</h1></center>
        <ul class="profiles">
          <?php
          foreach ($cases as $case) {
          ?>
          <li>
            <h4> <?php echo $case -> case_desc ;?></h4>
            <a href="#thumb<?php echo $case -> case_id ;?>" class="thumbnail" style="background-image: url('<?php echo $case -> case_img ;?>');background-size: 100% 100%;   "></a>
            <?php
            }
            ?>
          </ul>
          
        </div>
        <div class="portfolio-content">
          <div class="container">
            <?php
            foreach ($cases as $case) {
            ?>
            <div id="thumb<?php echo $case -> case_id ;?>" class="detail"   >
              <h1><?php echo $case -> case_mainTitle ;?></h1>
              <p><?php echo $case -> case_content ;?></p>
            </div>
            <?php
            }
            ?>
          </div>
        </div>
      </div>
      <div id="about">
        <div class="container">
          <div class="row">
            <div class="col-md-6" >
              <h1>ABOUT US</h1>
              <p>
                北京慧灵思投资管理有限公司
                前身为北京慧灵思广告传媒有限公司成立于2013年3月。
                公司广告事业部从事于为广告客户提供线上、线下媒体渠道投
                放策略服务；综合营销策划及执行服务；产品设计服务。
                公司旗下慧播网以智慧传“播”为目标，致力于打造
                全新的广告营销模式借助当下最流行的传播方式，以投放
                效果为根本，以直播内容为元素，以主播资源为途径，
                以直播平台为载体。首次创建了广告+主播+平台的全新营销模式。
              </p>
            </div>
            <div class="col-md-6" >
              <img src="img/about.jpg" alt="">
            </div>
          </div>
        </div>
      </div>
      
      <footer class="footer navbar-static-bottom wrap" >
        <div class="container wrap">
          <div class="row">
            <div class="col-md-12 col-sm-12 col-xs-12  footer-section footer-info">
              <div class="contact-info">
                <p><span><i class="fa fa-phone"></i></span> 客服电话: <a href="tel:01085954789">010-85954789</a></p>
                <p><span><i class="fa fa-envelope"></i></span> 公司邮箱: <a href="mailto:feelings_admcl@126.com">feelings_admcl@126.com</a></p>
                
              </div>
            </div>
          </div>
        </div>
      </footer>
      <div class="copy col-md-12 bg-primary" style="display: fixed; bottom:0;"><i class="fa fa-copyright"></i> 2016-2016 京ICP备16044422号 | 北京慧灵思投资管理有限公司feelingsmedia.com 版权所有</div>
      <!-- <footer></footer> -->
   
        
     
      <script src="js/jquery-1.11.3.min.js"> </script>
      <script src="js/bootstrap.min.js"></script>
      <script src="js/holder.js"></script>
      <script src="js/login-xin.js"></script>
      <script src="js/index-login.js"></script>
      <script src="js/stats.js"></script>
      <script src="js/angular.js"></script>
      <script src="js/index.js"></script>
      
      <!--   <script src="assets/js/amazeui.min.js"></script> -->

 <script>
  $(function () {
     $('[data-toggle="tooltip"]').tooltip();
  });
</script>
<!-- ???? -->


    </body>
  </html>