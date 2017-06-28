
### Fast parallel object cache for iOS

#Usage

1.file
```markdown
//创建
    _fileCache = [[DLFileCache alloc] init];
    _fileCache.cachePath = [NSString stringWithFormat:@"%@/ImageCache", [DLSandbox libCachePath]];
    _fileCache.cacheUser = @"user1";
    
//保存
    [self saveData:[NSData dataFromResource:@"icon_moreOperation_shareYouTube@2x.png"] forURL:@"test1"];
    
//删除
[self deleteImageForURL:@"test1"];
    
//获取
UIImage *imgae = [self pathImage:@"test1"];

//缓存路径
NSString *path = [self pathImageForURL:@"test1"];
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/LimingZou/dl-cache-ios-1/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.


