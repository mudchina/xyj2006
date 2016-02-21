#include <ansi.h>

int main(object me, string arg)
{
	string loc;
        int mana_cost;
	object ridee, map;
	string ridemsg;

        seteuid(getuid());

        if( me->is_fighting() )
                return notify_fail("你正在战斗，飞不开。\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("你正忙着呢，没工夫腾云驾雾。\n");
	if( !wizardp(me) && !environment(me)->query("outdoors") )
		return notify_fail("周围没有一片云，没办法腾云驾雾。\n");
	if( me->is_ghost() )
		return notify_fail("做了鬼了，就老实点吧！\n");
        if( !arg )
                return notify_fail("你要飞到哪里去？\n");
	if( me->query_temp("no_move") )
	    return notify_fail("你被定住了，哪里飞得起来！\n");

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
		< RANK_D->grade_dx(BLU "初领妙道" NOR) )
	{
		message_vision(HIY
"$N奋力望上一跳，似乎想飞起来。结果离地不到三尺就一个倒栽葱摔了下来。\n"
NOR, me);
		return notify_fail("你现在还初领妙道都谈不上，哪里飞得起来。\n");
	}

	if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
		< RANK_D->grade_fali(HIB "腾云驾雾" NOR) )
	{
		message_vision(HIY
"$N奋力望上一跳，似乎想飞起来。结果离地不到三尺就一个倒栽葱摔了下来。\n"
NOR, me);
		return notify_fail("看来以你的法力修为还不能腾云驾雾。\n");
	}

	if( (int)me->query("mana") < 200 )
	{
		message_vision(HIY
"$N奋力望上一跳，似乎想飞起来。结果离地不到三尺就一个倒栽葱摔了下来。\n"
NOR, me);
		return notify_fail("你目前法力不够充盈。\n");
	}


        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
                return
notify_fail("你现在头脑不太清醒，当心掉下来摔死。\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
                return
notify_fail("你想飞起来，可是体力似乎有点不支。\n");

        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        if(mana_cost > 0) mana_cost=0;

                        if( (string)me->query("family/family_name") == "月宫") 
                {
                message_vision(HIM"$N妩媚一笑，欣然起舞，随着一阵花香，已消失在月光中…… \n\n"NOR, me);
                }

                else if( (string)me->query("family/family_name") == "东海龙宫") 
                {
                message_vision(HIC"$N摇身一变，现出原形，正是一条神龙，随即穿云而去…… \n\n"NOR, me);
                }

        else if( (string)me->query("family/family_name") == "大雪山") 
                {
                message_vision(HIW"$N随手一挥，只见一团雪雾裹住真身，旋转而去…… \n\n"NOR, me);
                }

                else if( (string)me->query("family/family_name") == "方寸山三星洞") 
                {
                message_vision(HIG"$N捻个口诀，口中念动真言，大叫一声：“筋斗云！”只见天上降下一朵七色云彩，你纵身跃上，飞驰而去......\n\n"NOR, me);
                }

                else if( (string)me->query("family/family_name") == "五庄观") 
                {
                message_vision(HIB"$N大袖一摆，只见风起云涌，人已借风云之势在空中大步迈去…… \n\n"NOR, me);
                }

                else if( (string)me->query("family/family_name") == "将军府") 
                {
                message_vision(HIR"$N撮唇吹了一个响哨，一匹神骏的宝马随声而至，你纵身上马，绝尘而去…… \n\n"NOR, me);
                }

                else if( (string)me->query("family/family_name") == "火云洞") 
                {
                message_vision(RED"$N捻个口诀，口中念动真言,突然“轰”地冒起一团红雾,你随即隐入红雾中.\n\n"NOR, me);
                }

                else if( (string)me->query("family/family_name") == "南海普陀山") 
                {
                message_vision(HIY"$N口中念着佛号，脚下升起祥云，缓缓离地飞去…… \n\n"NOR, me);
                }
                else 
                {               message_vision(HIY"$N手一指，召来一朵云彩，高高兴兴地坐了上去，\n"+"再吹一声口哨，随之往上冉冉地升起。。。\n\n"NOR, me);            }
 me->add("mana", mana_cost);

        if(arg=="stone") loc="/d/dntg/hgs/entrance";
        else if(arg=="kaifeng") loc="/d/kaifeng/tieta";
        else if(arg=="moon") loc="/d/moon/ontop2";
        else if(arg=="lingtai") loc="/d/lingtai/gate";
        else if(arg=="putuo") loc="/d/nanhai/gate";
        else if(arg=="changan") loc="/d/city/center";
        else if(arg=="sky") loc="/d/dntg/sky/nantian";
		else if(arg=="wuzhuang") loc="/d/qujing/wuzhuang/gate";
		else if(arg=="meishan") loc="/d/meishan/erlangwai";

	else if(arg=="penglai") {
		if(!(map=present("eastsea map", me)) && !wizardp(me)) {
			write("你在天上转了半天也不知该往那边飞。。。\n");
			message_vision("\n$N失望地从云上跳了下来！\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="张" ){
			write("你在天上转了半天也不知该往那边飞。。。\n");
                        message_vision("\n$N失望地从云上跳了下来！\n", me);
                        return 1;
                        }
		loc="/d/penglai/penglai";
	}
	else if(arg=="xueshan") {
		if(!(map=present("xueshan map", me)) && !wizardp(me)) {
			write("你在天上转了半天也不知该往那边飞。。。\n");
			message_vision("\n$N失望地从云上跳了下来！\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="张" ){
                        write("你在天上转了半天也不知该往那边飞。。。\n");
                        message_vision("\n$N失望地从云上跳了下来！\n", me);
                        return 1;
                        }
		loc="/d/xueshan/binggu";
	}
	else if(arg=="baoxiang"){
		loc = "/d/qujing/baoxiang/bei1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="pingding"){
		loc = "/d/qujing/pingding/ping1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="yalong"){
		loc = "/d/qujing/pingding/yalong1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="wuji"){
		loc = "/d/qujing/wuji/square.c";
		//loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="chechi"){
		loc = "/d/qujing/chechi/jieshi1.c";
		loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="tongtian"){
		loc = "/d/qujing/tongtian/hedong1.c";
		loc[strlen(loc)-3] = '1'+random(6);
	}else if(arg=="jindou"){
		loc = "/d/qujing/jindou/jindou1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="nuerguo"){
		loc = "/d/qujing/nuerguo/towna1.c";
	loc[strlen(loc)-4] = 'a'+random(3);
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="dudi"){
		loc = "/d/qujing/dudi/dudi1.c";
		loc[strlen(loc)-3] = '1'+random(4);
        }else if(arg=="firemount"){
         	loc = "/d/qujing/firemount/cuiyun1.c";
		loc[strlen(loc)-3] = '1'+random(5);
	}else if(arg=="jilei"){
		loc = "/d/qujing/jilei/jilei1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="jisaiguo"){
		loc = "/d/qujing/jisaiguo/east1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="jingjiling"){
		loc = "/d/qujing/jingjiling/jingji1.c";
	}else if(arg=="xiaoxitian"){
		loc = "/d/qujing/xiaoxitian/simen.c";
        }else if(arg=="zhuzi"){
         	loc = "/d/qujing/zhuzi/zhuzi1.c";
		loc[strlen(loc)-3] = '1'+random(5);
        }else if(arg=="qilin"){
         	loc = "/d/qujing/qilin/yutai.c";
        }else if(arg=="pansi"){
         	loc = "/d/qujing/pansi/ling1.c";
		loc[strlen(loc)-3] = '1'+random(6);
        }else if(arg=="biqiu"){
         	loc = "/d/qujing/biqiu/jie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="qinghua"){
         	loc = "/d/qujing/biqiu/zhuang.c";
	}else if(arg=="wudidong"){
		loc = "/d/qujing/wudidong/firemount-wudidong3.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else if(arg=="qinfa"){
         	loc = "/d/qujing/qinfa/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="yinwu"){
         	loc = "/d/qujing/yinwu/huangye1.c";
        }else if(arg=="fengxian"){
         	loc = "/d/qujing/fengxian/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="yuhua"){
         	loc = "/d/qujing/yuhua/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="baotou"){
         	loc = "/d/qujing/baotou/shanlu1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="zhujie"){
         	loc = "/d/qujing/zhujie/shanlu11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="jinping"){
         	loc = "/d/qujing/jinping/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(7);
        }else if(arg=="qinglong"){
         	loc = "/d/qujing/qinglong/shanjian.c";
        }else if(arg=="tianzhu"){
         	loc = "/d/qujing/tianzhu/jiedao11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="maoying"){
         	loc = "/d/qujing/maoying/shanpo1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="lingshan"){
         	loc = "/d/qujing/lingshan/dalu1.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else{
                write("\n\n到了！你按下云头跳了下来。\n");
                write("咦？．．．怎么还在原来的地方？\n");
                return 1;
        }

if (! loc)
		return 1;
		
	// mon /10/18/98
	if(MISC_D->random_capture(me,0,1)) return 1;

	if (ridee = me->ride()) {
	  ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
	  ridee->move(loc);
	}  
	else  
	  ridemsg = "";
	                                            	
	me->move(loc);
        write("\n\n到了！你按下云头跳了下来。\n");
        if( (string)me->query("family/family_name")=="东海龙宫")
        {               message_vision(HIC"\n半空中仿佛冲出一条水柱，$N"+ridemsg+"从水柱上稳稳跳落地下…… \n"NOR, me);

        }

        else if ( (string)me->query("family/family_name")=="阎罗地府")
        {
                message_vision(HIY"\n只见平地吹起一阵阴风，$N"+ridemsg+"从里面走了出来。\n"NOR, me);

        }

        else if ( (string)me->query("family/family_name")=="月宫")
        {
                message_vision(HIM"\n只见一道月光洒在你面前，柔柔的，冷冷的，$N"+ridemsg+"从中飘然而至…… \n"NOR, me);

        }

        else if ( (string)me->query("family/family_name")=="大雪山")
        {
                message_vision(HIW"\n霎时间，大雪纷飞，$N"+ridemsg+"亦如晶莹剔透的雪花随风飘下……  \n"NOR, me);
 
        }

        else if ( (string)me->query("family/family_name")=="方寸山三星洞")
        {
                message_vision(HIG"\n 只听见天上传来一声：“俺来也！”，人随声到，$N"+ridemsg+"从筋斗云中冉冉落下……\n"NOR, me); 

        }

        else if ( (string)me->query("family/family_name")=="五庄观")
        {
                message_vision(HIB"\n 一阵清风吹来，$N"+ridemsg+"从空中降落……\n"NOR, me);
 
        }

        else if ( (string)me->query("family/family_name")=="将军府")
        {
                message_vision(HIB"\n 震耳欲聋的一声：“本将在此！”，$N"+ridemsg+"已来到大家眼前。\n"NOR, me);

        }
        else if ( (string)me->query("family/family_name")=="火云洞")
        {
                message_vision(RED"\n 一团红色的烟雾涌了过来,$N"+ridemsg+"突然从里面蹦了出来.\n"NOR, me);
        }

        else if ( (string)me->query("family/family_name")=="南海普陀山")
        {
                message_vision(HIY"\n 一声洪亮的“南无阿伲陀佛”，$N"+ridemsg+"已从佛光中，祥云里走出…….\n"NOR, me);
        }       
    return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : fly|fei [目的地]

当你的道行和法力高强时，你可以腾云驾雾。

目前你可以飞到的地方：
changan         ->长安城                 kaifeng        ->开封城
stone           ->花果山仙石             sky            ->南天门
moon      	->昆仑山月宫             penglai        ->蓬莱仙岛
lingtai         ->灵台方寸山    	 putuo     	->南海普陀山
xueshan	        ->大雪山寒冰谷           meishan        ->梅山灌江口
wuzhuang        ->万寿山五庄观

baoxiang	->宝象国		 pingding  	->平顶山
yalong    	->压龙山 		 wuji           ->乌鸡国
chechi		->车迟国 		 tongtian	->通天河
jindou  	->金兜山 		 nuerguo	->女儿国
dudi   		->毒敌山 		 firemount	->火焰山
jilei    	->积雷山 		 jisaiguo	->祭赛国
jingjiling	->荆棘岭		 xiaoxitian	->小西天
zhuzi		->朱紫国		 qilin		->麒麟山
pansi		->盘丝岭		 biqiu		->比丘国 
qinghua		->清华庄		 wudidong       ->无底洞
qinfa           ->钦法国		 fengxian	->凤仙郡 
yinwu    	->隐雾山		 yuhua   	->玉华县 
baotou  	->豹头山		 zhujie  	->竹节山
jinping 	->金平府		 qinglong	->青龙山 
tianzhu 	->天竺国		 maoying 	->毛颖山 
lingshan	->灵山                   

HELP
        );
        return 1;
}


