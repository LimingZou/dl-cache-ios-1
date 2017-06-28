//
//  NSString+DLExtension.h
//  DLFoundation
//
//  Created by limingzou on 2017/5/12.
//  Copyright © 2017年 limingzou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef NSString *			(^NSStringAppendBlock)( id format, ... );
typedef NSString *			(^NSStringReplaceBlock)( NSString * string, NSString * string2 );

typedef NSMutableString *	(^NSMutableStringAppendBlock)( id format, ... );
typedef NSMutableString *	(^NSMutableStringReplaceBlock)( NSString * string, NSString * string2 );

#pragma mark -

#undef	FORMAT
#define	FORMAT( __fmt, ... )	[NSString stringWithFormat:__fmt, __VA_ARGS__]

#undef	FORMAT_NSINTEGER
#define	FORMAT_NSINTEGER( __integerValue )	[NSString stringWithNSInteger:__integerValue]

#undef	FORMAT_CGFLOAT
#define	FORMAT_CGFLOAT( __floatValue )	[NSString stringWithCGFloat:__floatValue]

#undef	FORMAT_CGFLOAT_DECIMAL
#define	FORMAT_CGFLOAT_DECIMAL( __floatValue, __decimal )	[NSString stringWithCGFloat:__floatValue decimal:__decimal]

#pragma mark -

@interface NSString (DLExtension)

@property (nonatomic, readonly) NSStringAppendBlock		APPEND;
@property (nonatomic, readonly) NSStringAppendBlock		LINE;
@property (nonatomic, readonly) NSStringReplaceBlock	REPLACE;

@property (nonatomic, readonly) NSData *				data;
@property (nonatomic, readonly) NSDate *				date;

@property (nonatomic, readonly) NSString *				MD5;
@property (nonatomic, readonly) NSData *				MD5Data;

@property (nonatomic, readonly) NSString *				SHA1;
- (NSArray *)allURLs;

- (NSString *)urlByAppendingDict:(NSDictionary *)params;
- (NSString *)urlByAppendingDict:(NSDictionary *)params encoding:(BOOL)encoding;
- (NSString *)urlByAppendingArray:(NSArray *)params;
- (NSString *)urlByAppendingArray:(NSArray *)params encoding:(BOOL)encoding;
- (NSString *)urlByAppendingKeyValues:(id)first, ...;

+ (NSString *)queryStringFromDictionary:(NSDictionary *)dict;
+ (NSString *)queryStringFromDictionary:(NSDictionary *)dict encoding:(BOOL)encoding;;
+ (NSString *)queryStringFromArray:(NSArray *)array;
+ (NSString *)queryStringFromArray:(NSArray *)array encoding:(BOOL)encoding;;
+ (NSString *)queryStringFromKeyValues:(id)first, ...;

- (NSString *)URLEncoding;
- (NSString *)URLDecoding;

- (NSString *)trim;
- (NSString *)unwrap;
- (NSString *)repeat:(NSUInteger)count;
- (NSString *)normalize;

- (BOOL)match:(NSString *)expression;
- (BOOL)matchAnyOf:(NSArray *)array;

- (BOOL)empty;
- (BOOL)notEmpty;

- (BOOL)eq:(NSString *)other;
- (BOOL)equal:(NSString *)other;

- (BOOL)is:(NSString *)other;
- (BOOL)isNot:(NSString *)other;

- (BOOL)isValueOf:(NSArray *)array;
- (BOOL)isValueOf:(NSArray *)array caseInsens:(BOOL)caseInsens;

- (BOOL)isNormal;
- (BOOL)isTelephone;
- (BOOL)isMobilephone;
- (BOOL)isUserName;
- (BOOL)isChineseUserName;
- (BOOL)isChineseName;
- (BOOL)isPassword;
- (BOOL)isEmail;
- (BOOL)isUrl;
- (BOOL)isIPAddress;

- (NSString *)substringFromIndex:(NSUInteger)from untilString:(NSString *)string;
- (NSString *)substringFromIndex:(NSUInteger)from untilString:(NSString *)string endOffset:(NSUInteger *)endOffset;

- (NSString *)substringFromIndex:(NSUInteger)from untilCharset:(NSCharacterSet *)charset;
- (NSString *)substringFromIndex:(NSUInteger)from untilCharset:(NSCharacterSet *)charset endOffset:(NSUInteger *)endOffset;

- (NSUInteger)autoLength;
- (NSUInteger)countFromIndex:(NSUInteger)from inCharset:(NSCharacterSet *)charset;

+ (NSString *)fromResource:(NSString *)resName;

@end

@interface NSString (DLStringFormat)

+ (instancetype)stringWithNSInteger:(NSInteger)integerValue;
+ (instancetype)stringWithCGFloat:(CGFloat)floatValue;
+ (instancetype)stringWithCGFloat:(CGFloat)floatValue decimal:(NSUInteger)decimal;

@end

@interface NSMutableString(DLExtension)

@property (nonatomic, readonly) NSMutableStringAppendBlock	APPEND;
@property (nonatomic, readonly) NSMutableStringAppendBlock	LINE;
@property (nonatomic, readonly) NSMutableStringReplaceBlock	REPLACE;

@end
