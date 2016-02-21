// title.c (Mon  09-04-95) 
//mofied for set title...Weiqi 09/31/97.

#include <ansi.h>
inherit F_CLEAN_UP;

int check_legal_title(string, int);
 
int main(object me, string arg)
{
	int titlelength=0;

	if( !arg ){
    		printf("你目前的头衔及门派：\n");
    		printf(BOLD "%s" NOR " %s\n\n", RANK_D->query_rank(me), me->short(1));
    		if(strlen(me->query("added_title"))>1)
		  printf("其中头衔自设部份：%s\n", (string)me->query("added_title"));
    		return 1;
	}
	
	if( arg=="none" ) {
		me->delete("added_title");
		printf("好，删掉头衔自设部份。\n");
		return 1;
	}

	if(me->query("daoxing") >= 500000){
		titlelength=8;
	}
	else if(me->query("daoxing") >= 100000){
		titlelength=4;
	}
	else titlelength=0;
	
	if(check_legal_title(arg, titlelength) == 0) return 1;	
	
	me->set("added_title", arg);

    	return 1;
}
 
int check_legal_title(string addtitle, int titlelength)
{
       	int i;

	i = strlen(addtitle);

	if(titlelength<=0){
		write("对不起，目前你还不能给自己设头衔。\n");
    		return 0;
	}

	if(titlelength < strlen(addtitle)){
    		printf("对不起，目前你最多只能设%s个中文字作为头衔。\n", chinese_number(titlelength/2));
    		return 0;
	}

	while(i--) {
               	if( addtitle[i]<=' ' ) {
                       	write("对不起，你的头衔不能用控制字元。\n");
                       	return 0;
               	}
               	if( i%2==0 && !is_chinese(addtitle[i..<0]) ) {
                       	write("对不起，请您用「中文」设头衔。\n");
                       	return 0;
               	}
       	}

	return 1;
}

int help(object me)
{
    write(@HELP
指令格式: title ***
 
自己设定头衔。道行超过500年可以设4个中文字，
超过100年可以设2个中文字，少于100年还得加油:)

title 不加参数显示你目前的头衔及门派。
title none  删掉头衔自设部份。

HELP
    );
	return 1;
}
 
