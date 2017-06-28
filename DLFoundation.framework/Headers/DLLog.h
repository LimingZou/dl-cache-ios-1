//
//  DLLog.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DLFoundation/DLSingleton.h>
#import <DLFoundation/NSObject+DLJSON.h>

#pragma mark -

typedef NS_ENUM(NSInteger, DLLogLevel)
{
    DLLogLevelNone		= 0,
    DLLogLevelInfo		= 100,
    DLLogLevelPerf		= 200,
    DLLogLevelWarn		= 300,
    DLLogLevelError	    = 400
};

#pragma mark -

#undef	CC
#define CC( ... )		[[DLLogger sharedInstance] file:@(__FILE__) line:__LINE__ function:@(__PRETTY_FUNCTION__) level:DLLogLevelNone format:__VA_ARGS__];

#undef	INFO
#define INFO( ... )		[[DLLogger sharedInstance] file:@(__FILE__) line:__LINE__ function:@(__PRETTY_FUNCTION__) level:DLLogLevelInfo format:__VA_ARGS__];

#undef	PERF
#define PERF( ... )		[[DLLogger sharedInstance] file:@(__FILE__) line:__LINE__ function:@(__PRETTY_FUNCTION__) level:DLLogLevelPerf format:__VA_ARGS__];

#undef	WARN
#define WARN( ... )		[[DLLogger sharedInstance] file:@(__FILE__) line:__LINE__ function:@(__PRETTY_FUNCTION__) level:DLLogLevelWarn format:__VA_ARGS__];

#undef	ERROR
#define ERROR( ... )	[[DLLogger sharedInstance] file:@(__FILE__) line:__LINE__ function:@(__PRETTY_FUNCTION__) level:DLLogLevelError format:__VA_ARGS__];

#undef	PRINT
#define PRINT( ... )	[[DLLogger sharedInstance] file:@(__FILE__) line:__LINE__ function:@(__PRETTY_FUNCTION__) level:DLLogLevelNone format:__VA_ARGS__];

#undef	VAR_DUMP
#define VAR_DUMP( __obj )	PRINT( [__obj description] );

#undef	OBJ_DUMP
#define OBJ_DUMP( __obj )	PRINT( [__obj objectToDictionary] );

@interface DLBacklog : NSObject
@property (nonatomic, retain) NSString *		module;
@property (nonatomic, assign) DLLogLevel		level;
@property (nonatomic, readonly) NSString *		levelString;
@property (nonatomic, retain) NSString *		file;
@property (nonatomic, assign) NSUInteger		line;
@property (nonatomic, retain) NSString *		func;
@property (nonatomic, retain) NSDate *			time;
@property (nonatomic, retain) NSString *		text;
@end

#pragma mark -

@interface DLLogger : NSObject

AS_SINGLETON( DLLogger );

@property (nonatomic, assign) BOOL				showLevel;
@property (nonatomic, assign) BOOL				showModule;
@property (nonatomic, assign) BOOL				enabled;
@property (nonatomic, retain) NSMutableArray *	backlogs;
@property (nonatomic, assign) NSUInteger		indentTabs;

- (void)toggle;
- (void)enable;
- (void)disable;

- (void)indent;
- (void)indent:(NSUInteger)tabs;
- (void)unindent;
- (void)unindent:(NSUInteger)tabs;

- (void)file:(NSString *)file line:(NSUInteger)line function:(NSString *)function level:(DLLogLevel)level format:(NSString *)format, ...;
- (void)file:(NSString *)file line:(NSUInteger)line function:(NSString *)function level:(DLLogLevel)level format:(NSString *)format args:(va_list)args;


@end

#pragma mark -

#if __cplusplus
extern "C" {
#endif
    
    void DLLog( NSString * format, ... );
    
#if __cplusplus
};
#endif

