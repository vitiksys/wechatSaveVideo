#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WeChatHead.h"
%hook WCTimeLineViewController
- (void)tableView:(id)tblView didSelectRowAtIndexPath:(NSIndexPath *)IndexPath{
    %orig;
    WCFacade *wcFacade = [(MMServiceCenter *)[%c(MMServiceCenter) defaultCenter] getService: [%c(WCFacade) class]];
    WCDataItem * dataItem=[wcFacade getTimelineDataItemOfIndex:[self calcDataItemIndex:IndexPath.section]];
    NSLog(@"dataItem %@",dataItem);

    for(WCMediaItem *item in dataItem.contentObj.mediaList){
        NSLog(@"content %@",

              item.dataUrl.url

              );
        if(item.dataUrl){
            [self DownloadVideo:item.dataUrl.url];
        }
    }


}
%new
-(void)DownloadVideo:(NSString *)urlToDownload
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSLog(@"Downloading Started");

        NSURL  *url = [NSURL URLWithString:urlToDownload];
        NSData *urlData = [NSData dataWithContentsOfURL:url];
        if ( urlData )
        {

            NSArray       *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
            NSString  *documentsDirectory = [paths objectAtIndex:0];

            NSString  *filePath = [NSString stringWithFormat:@"%@/%@", documentsDirectory,@"thefile.mp4"];
            NSLog(@"%@",filePath);
            
            dispatch_async(dispatch_get_main_queue(), ^{
                [urlData writeToFile:filePath atomically:YES];
                UISaveVideoAtPathToSavedPhotosAlbum(filePath, nil, nil, nil);
                NSLog(@"File Saved !");
            });
        }
        
    });
    
}
%end
