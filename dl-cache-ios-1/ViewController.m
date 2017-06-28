//
//  ViewController.m
//  dl-cache-ios-1
//
//  Created by limingzou on 2017/6/28.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import "ViewController.h"
#import "DLCache.h"
@interface ViewController ()
{
    DLFileCache *    _fileCache;
    DLKeychain *     _keyChain;
    DLMemoryCache *  _memoryCache;
    DLUserDefaults * _userDefaults;
}
@property (atomic, retain) DLFileCache *    fileCache;
@property (atomic, retain) DLKeychain *     keyChain;
@property (atomic, retain) DLMemoryCache *  memoryCache;
@property (atomic, retain) DLUserDefaults * userDefaults;

@end


@implementation ViewController

@synthesize fileCache = _fileCache;
@synthesize keyChain = _keyChain;
@synthesize memoryCache = _memoryCache;
@synthesize userDefaults = _userDefaults;

- (void)load{
    [self dl_file];
    [self dl_keychain];
    [self dl_userDefaults];
    [self dl_memory];
}

#pragma mark -memory

- (void)dl_memory{
    /*maclloc*/
    _memoryCache = [DLMemoryCache sharedInstance];
    
    /*save*/
    [_memoryCache setObject:@"memory-value" forKey:@"memory-key"];
    
    /*delete*/
    [_memoryCache removeObjectForKey:@"memory-key"];

    /*fetch */
    [_memoryCache objectForKey:@"memory-key"];

}

#pragma mark - userDefaults

- (void)dl_userDefaults{
    /*maclloc*/
    _userDefaults = [DLUserDefaults sharedInstance];
    
    /*save*/
    [_userDefaults userDefaultsWrite:@"userDefaults-value" forKey:@"userDefaults-key"];
    
    /*delete*/
    [_userDefaults userDefaultsRemove:@"userDefaults-key"];
    
     /*fetch */
    [_userDefaults userDefaultsRead:@"userDefaults-key"];

}

#pragma mark  - keychain

- (void)dl_keychain{
    /*maclloc*/
    _keyChain =  [DLKeychain sharedInstance];
    _keyChain.defaultDomain = @"com.keychain.";
    
    /*save*/
    [_keyChain keychainWrite:@"keychain-value" forKey:@"keychain-key"];
    
    /*delete*/
    [_keyChain keychainDelete:@"keychain-key"];
    
    /*fetch */
    [_keyChain keychainRead:@"keychain-key"];
    
}

#pragma mark  - file cache
- (void)dl_file{
    /*maclloc*/
    _fileCache = [[DLFileCache alloc] init];
    _fileCache.cachePath = [NSString stringWithFormat:@"%@/ImageCache", [DLSandbox libCachePath]];
    _fileCache.cacheUser = @"user1";
    
    /*save*/
    [self saveData:[NSData dataFromResource:@"icon_moreOperation_shareYouTube@2x.png"] forURL:@"test1"];
    
    /*delete*/
    //[self deleteImageForURL:@"test1"];
    
    /*fetch */
    [self pathImage:@"test1"];
    
    NSLog(@"imageCacheUrl:%@",[self pathImageForURL:@"test1"]);
}


- (void)saveData:(NSData *)data forURL:(NSString *)string
{
    PERF_ENTER
    
    NSString * cacheKey = [string MD5];
    [self.fileCache setObject:data forKey:cacheKey];
    
    PERF_LEAVE
}

- (void)deleteImageForURL:(NSString *)string
{
    PERF_ENTER
    
    NSString * cacheKey = [string MD5];
    [self.fileCache removeObjectForKey:cacheKey];
    
    PERF_LEAVE
}

- (NSString *)pathImageForURL:(NSString *)string{
    NSString * cacheKey = [string MD5];
    return [self.fileCache fileNameForKey:cacheKey];
}

- (UIImage *)pathImage:(NSString *)string{
    NSString * cacheKey = [string MD5];
    return [UIImage imageWithData:[self.fileCache objectForKey:cacheKey]];
}


- (void)viewDidLoad {
    [super viewDidLoad];
    [self performLoad];
}
@end
