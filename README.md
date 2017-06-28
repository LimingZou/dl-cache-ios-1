
### Fast parallel object cache for iOS

#Dependencies
* DLFoundation 是一个功能性框架, 使用此框架能大量减少开发的时间成本
* 详细介绍[DLFoundation]()
#How To Use

* file
```markdown
Objective-C:

    /*创建*/
    _fileCache = [[DLFileCache alloc] init];
    _fileCache.cachePath = [NSString stringWithFormat:@"%@/ImageCache", [DLSandbox libCachePath]];
    _fileCache.cacheUser = @"user1";
    
    /*保存*/
    [_fileCache setObject:[NSData dataFromResource:@"testImage.png"] forKey:@"test1"];
    
    /*删除*/
    [_fileCache removeObjectForKey:@"test1"];
    
    /*获取*/
    NSData *imgaeData = [_fileCache objectForKey:@"test1"];

    /*缓存路径*/
    NSString *path = [_fileCache fileNameForKey:@"test1"];
```

-------

* Memory
```markdown
Objective-C:

    /*创建*/
    _memoryCache = [DLMemoryCache sharedInstance];
    
    /*保存*/
    [_memoryCache setObject:@"memory-value" forKey:@"memory-key"];
    
    /*删除*/
    [_memoryCache removeObjectForKey:@"memory-key"];

    /*获取*/
    [_memoryCache objectForKey:@"memory-key"];
```
-------

* userDefaults
```markdown
Objective-C:

    /*创建*/
    _userDefaults = [DLUserDefaults sharedInstance];
    
    /*保存*/
    [_userDefaults userDefaultsWrite:@"userDefaults-value" forKey:@"userDefaults-key"];
    
    /*删除*/
    [_userDefaults userDefaultsRemove:@"userDefaults-key"];
    
     /*获取*/
    [_userDefaults userDefaultsRead:@"userDefaults-key"];

```
-------

* keychain
```markdown
Objective-C:

    /*创建*/
    _keyChain =  [DLKeychain sharedInstance];
    _keyChain.defaultDomain = @"com.keychain.";
    
    /*保存*/
    [_keyChain keychainWrite:@"keychain-value" forKey:@"keychain-key"];
    
    /*删除*/
    [_keyChain keychainDelete:@"keychain-key"];
    
    /*获取*/
    [_keyChain keychainRead:@"keychain-key"];
```

For more details see [GitHub Flavored Markdown](https://github.com/LimingZou).
###Communication
* If you found a bug, open an issue.
### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/LimingZou/dl-cache-ios-1/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.

###Contact us
* QQ: 402016082
* Email: 402016082@qq.com


