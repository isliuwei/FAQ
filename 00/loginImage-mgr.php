material_edit.php<!doctype html>
<html class="no-js">
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>feelingsmedia后台管理</title>
    <meta name="description" content="这是一个form页面">
    <meta name="keywords" content="form">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
    <meta name="renderer" content="webkit">
    <meta http-equiv="Cache-Control" content="no-siteapp" />
    <base href="<?php echo site_url();?>">
    <link rel="icon" type="image/png" href="assets/i/favicon.png">
    <link rel="apple-touch-icon-precomposed" href="assets/i/app-icon72x72@2x.png">
    <meta name="apple-mobile-web-app-title" content="Amaze UI" />
    <link rel="stylesheet" href="assets/css/amazeui.min.css"/>
    <link rel="stylesheet" href="assets/css/admin.css">
</head>
<body>
<!--[if lte IE 9]>
<p class="browsehappy">你正在使用<strong>过时</strong>的浏览器，Amaze UI 暂不支持。 请 <a href="http://browsehappy.com/" target="_blank">升级浏览器</a>
    以获得更好的体验！</p>
<![endif]-->


<?php include 'admin-header.php'; ?>

<div class="am-cf admin-main">
    <!-- sidebar start -->
    <?php include 'admin-sidebar.php'; ?>
    <!-- sidebar end -->

    <!-- content start -->
    <div class="admin-content">
        <div class="am-cf am-padding">
            <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">案例更新界面</strong> / <small>Update Case</small></div>
        </div>

        <div class="am-tabs am-margin" data-am-tabs>
            <ul class="am-tabs-nav am-nav am-nav-tabs">
                
            </ul>

            <div class="am-tabs-bd">
                <div class="am-tab-panel am-fade am-in am-active" id="tab1">
                    <form action="admin/update_case" method="post" class="am-form am-form-inline" enctype="multipart/form-data">

						<input type="hidden" value="<?php echo $case -> case_id;?>" name="case_id">
                        <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">案例主标题</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                                <input type="text" id="case-mainTitle" name="case_mainTitle"  value="<?php echo $case -> case_mainTitle ;?>">
                            </div>
                        </div>
                        <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">案例副标题</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                                <input type="text" id="case-subTitle" name="case_subTitle" value="<?php echo $case -> case_subTitle ;?>">
                            </div>
                        </div>

                        <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">案例类别</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                                <input type="text" id="case-cate" name="case_cate" value="<?php echo $case -> case_cate ;?>">
                            </div>
                        </div>

                        <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">案例描述</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                                <input type="text" id="case-desc" name="case_desc" value="<?php echo $case -> case_desc ;?>">
                            </div>
                        </div>

                         <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">案例时间</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                                <input type="text" id="case-time" name="case_time" value="<?php echo $case -> case_time ;?>">
                            </div>
                        </div>

                        <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">案例内容</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                               <textarea name="case_content" id="case-content" cols="30" rows="10"><?php echo $case -> case_content ;?></textarea>
                            </div>
                        </div>

                        <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">当前案例图片</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                                <input type="hidden" name="photo_old_url" value="<?php echo $case -> case_img  ;?>">
                                <img src="<?php echo $case -> case_img ;?>" style="width: 30%; cursor: pointer;" data-am-popover="{content: '当前案例缩略图', trigger: 'hover focus'}"/>
                            </div>
                        </div>


                        
                        <div class="am-g am-margin-top">
                            <div class="am-u-sm-4 am-u-md-2 am-text-right">案例图片</div>
                            <div class="am-u-sm-8 am-u-md-4 am-u-end">
                                <!--              文件上传-->
                                <div class="am-form-group am-form-file">
                                    <button type="button" class="am-btn am-btn-danger am-btn-sm">
                                        <i class="am-icon-cloud-upload"></i> 选择图片文件</button>
                                    <input id="doc-form-file" type="file" multiple name="case_img">
                                    <!--图片预览-->
                                    <br/>
                                    <br/>
                                    <small class="am-badge am-badge-success am-radius">预览图</small>
                                    <div id="imgdiv"><img id="imgShow" width="50%" /></div>
                                    <!--图片预览-->
                                </div>
                                <div id="file-list"></div>
                                <!--              文件上传-->
                            </div>
                        </div>

                        <div class="am-margin">
                            <input type="reset" class="am-btn am-btn-primary am-btn-xs" value="重置">
                            <input type="submit" class="am-btn am-btn-primary am-btn-xs" value="提交新增">
                            <button type="button" class="am-btn am-btn-primary am-btn-xs">放弃保存</button>
                        </div>

                    </form>
                </div>



            </div>
        </div>

        
    </div>
   

</div>

<a href="#" class="am-icon-btn am-icon-th-list am-show-sm-only admin-menu" data-am-offcanvas="{target: '#admin-offcanvas'}"></a>




<!-- <footer>
    <hr>
    <p class="am-padding-left">© 2014 AllMobilize, Inc. Licensed under MIT license.</p>
</footer> -->

<?php include 'copyright.php'; ?>

<!--[if lt IE 9]>
<script src="http://libs.baidu.com/jquery/1.11.1/jquery.min.js"></script>
<script src="http://cdn.staticfile.org/modernizr/2.8.3/modernizr.js"></script>
<script src="assets/js/amazeui.ie8polyfill.min.js"></script>
<![endif]-->

<!--[if (gte IE 9)|!(IE)]><!-->
<script src="assets/js/jquery.min.js"></script>
<!--<![endif]-->
<script src="assets/js/amazeui.min.js"></script>
<script src="assets/js/app.js"></script>



<!--图片上传-->
<script>
    $(function() {
        $('#doc-form-file').on('change', function() {
            var fileNames = '';
            $.each(this.files, function() {
                fileNames += '<span class="am-badge">' + this.name + '</span> ';
            });
            $('#file-list').html(fileNames);
        });
    });
</script>
<!--图片上传-->

<!--图片上传预览-->
<script src="js/uploadPreview.min.js"></script>
<script>
    window.onload = function () {
        new uploadPreview({ UpBtn: "doc-form-file", DivShow: "imgdiv", ImgShow: "imgShow" });
    }
</script>
<!--图片上传预览-->

</body>
</html>
