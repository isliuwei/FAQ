fis.match('::packager', {
  spriter: fis.plugin('csssprites')
});

// fis.match('*', {
//   useHash: false
// });

// fis.match('*.js', {
//   optimizer: fis.plugin('uglify-js')
// });

// fis.match('*.css', {
//   useSprite: true,
//   optimizer: fis.plugin('clean-css')
// });

// fis.match('*.png', {
//   optimizer: fis.plugin('png-compressor')
// });


// fis.match('*.{js,css,png}', {
//   useHash: true
// });

/**
fis.match('*.{js,css,png,gif}', {
    useHash: true // 开启 md5 戳
});

// 所有的 js
fis.match('**.js', {
    //发布到/static/js/xxx目录下
    release: '/static/js$0'
});

// 所有的 css
fis.match('**.css', {
    //发布到/static/css/xxx目录下
    release: '/static/css$0'
});

// 所有image目录下的.png，.gif文件
fis.match('/img/(*.{png,gif})', {
    //发布到/static/pic/xxx目录下
    release: '/static/pic/$1$2'
});
*/

