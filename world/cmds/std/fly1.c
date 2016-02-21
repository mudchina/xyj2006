//cglaem...12/17/96.

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

          if( (string)me->query("family/family_name") == "陷空山无底洞") {
                  message_vision(RED"只见$N口中念动有词，忽然双臂一振，空中雷轰电掣黑雾漫漫，但见电光飞闪$N随之消失…… \n\n"NOR, me);
}
           if( (string)me->query("family/family_name") == "将军府") {
      message_vision(HIR"$N撮唇吹了一个响哨，一匹神骏的宝马随声而至，$N纵身上马，绝尘而去…… \n\n"NOR, me);
}
	if( (string)me->query("family/family_name") == "阎罗地府") {
		message_vision(HIB"$N往黑暗处一指，只见所指之处仿佛出现一扇门，$N大步走入，门也随之消失…… \n\n"NOR, me);
              }
	if( (string)me->query("family/family_name") == "方寸山三星洞") {
		message_vision(HIG"$N捻个口诀，口中念动真言，只见祥光万道，白雾紫气，红云腾腾而起,$N纵身跃上，飞驰而去......\n\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "月宫") {
		message_vision(HIM"$N妩媚一笑，欣然起舞，随着一阵花香，已消失在月光中……\n"NOR, me);
              }
                if( (string)me->query("family/family_name") == "昆仑山玉虚洞") {
                message_vision(HIW"$N伸手一招，一朵莲花平地而起,$N坐上莲台，转眼而去……\n"NOR, me);
              }

		if( (string)me->query("family/family_name") == "盘丝洞") {
		message_vision(MAG"$N把口一张，吐出一道七色神光，笼罩其身，但见霞光一闪,$N化作一道彩虹消失的无影无踪……\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "五庄观") {
		message_vision(HIB"$N大袖一摆，平地起身，只见风起云涌，$N在空中连踏出乾坤八位，几步踏出，身形已然消失……\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "大雪山") {
		message_vision(HIW"$N随手一挥，阴风簇拥，一派寒雾笼罩真身，旋转而去…… \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "南海普陀山") {
		message_vision(HIY"$N口中念着佛号，脚下升起一朵莲花宝座，缓缓离地飞去……  \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "东海龙宫") {
		message_vision(HIC"$N口摇身一变，现出原形，正是一条神龙，随即穿云而去…… \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "火云洞") {
              message_vision(RED"$N口捻个口诀，口中念动真言,突然“轰”地冒起一团红雾,$N随即隐入红雾中。\n"NOR, me);
              }
if( (string)me->query("family/family_name") == "蜀山派") {
             message_vision(HIC"$N口捻个口诀，扔出一把宝剑，$N飞驰而上，一招「御剑飞行」向远方飞去。。。。\n"NOR, me);
     }
 

        me->add("mana", mana_cost);

        if(arg=="stone") loc="/d/dntg/hgs/entrance";
        else if(arg=="kunlun") loc="/d/kunlun/xiaolu3";
        else if(arg=="33tian") loc="/d/33tian/33tian";
        else if(arg=="kaifeng") loc="/d/kaifeng/tieta";
        else if(arg=="moon") loc="/d/moon/ontop2";
        else if(arg=="lingtai") loc="/d/lingtai/gate";
        else if(arg=="putuo") loc="/d/nanhai/gate";
        else if(arg=="changan") loc="/d/city/center";
        else if(arg=="sky") loc="/d/dntg/sky/nantian";
	 else if(arg=="wuzhuang") loc="/d/qujing/wuzhuang/gate";
	 else if(arg=="meishan") loc="/d/meishan/erlangwai";
         else if(arg=="shennong") loc="/d/liandan/road1";
        else if(arg=="wudang") loc="/d/wudang/xuanyuegate";
              else if(arg=="shushan") loc="/d/shushan/road1";
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
//		write("你驾着祥云向东边海中飞去。。。\n\n");
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
//		write("你驾着祥云向大雪山飞去。。。\n\n");
		loc="/d/xueshan/binggu";
	}
 else if(arg=="shennong") {
if(!wizardp(me)&&(int)me->query("learned_points")<200000)
            {  write("飞到那边要求要很高的。。。\n");
               message_vision("$N飞到半空中，似乎感到前途的危险，还是不敢去了！\n",me);
           return 1;
}
                 loc="/d/liandan/xiaolu";
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
		/*
		if (me->query("obstacle/nuerguo")!="done" && !wizardp(me)){
			write("\n一阵风把你东倒西歪地吹了回来！\n");
			write("看样子飞不过去。\n");
			return 1;
			}
		*/
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
//		}else if(arg=="hangzhou"){
//         	loc = "/d/hangzhou/road1.c";
//		}else if(arg=="emei"){
//         	loc = "/d/emei/jinding.c";
//		}else if(arg=="wutai"){
//         	loc = "/d/southern/wutai/qinglianggu.c";
		}else if(arg=="liusha"){
         	loc = "/d/qujing/liusha/riverside.c";
		}else if(arg=="heifeng"){
         	loc = "/d/qujing/heifeng/road4.c";
		}else if(arg=="yingjian"){
         	loc = "/d/qujing/yingjian/lakeside3.c";
//		}else if(arg=="guanyin"){
//         	loc = "/d/qujing/guanyin/shanmen.c";
		}else if(arg=="yunzhan"){
         	loc = "/d/qujing/yunzhan/shanlu1.c";
		}else if(arg=="shuangcha"){
         	loc = "/d/qujing/shuangcha/shanlu3.c";
		}else if(arg=="sisheng"){
         	loc = "/d/qujing/village/cunkou.c";
		}else if(arg=="huangfeng"){
         	loc = "/d/qujing/huangfeng/dongkou.c";
//		loc[strlen(loc)-3] = '1'+random(6);
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
//       write("\n\n到了！你按下云头跳了下来。\n");

          if( (string)me->query("family/family_name") == "陷空山无底洞") {
message_vision(RED"\n忽然间悲风飒飒，惨雾迷迷，阴云四合，风过数阵，“啪”的一股黑烟升起,$N"+ridemsg+RED"从黑烟中走了出来…… \n"
  NOR, me);
}
           if( (string)me->query("family/family_name") == "将军府") {
   message_vision(HIR"\n 震耳欲聋的一声：“本将在此！”，$N已来到大家眼前。\n"
  NOR, me);
}
	if( (string)me->query("family/family_name")=="阎罗地府") {
		message_vision(HIB"\n悲风四起，杀气漫空，黑暗暗俱是些鬼哭神嚎，伴随着冷森森的笑声，$N"+ridemsg+HIB"如魑魅般从黑暗中出现…… \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="方寸山三星洞") {
		message_vision(HIG"\n忽听得空中有一阵异香仙乐，飘飘而来,空中飘落一朵七彩祥云，$N"+ridemsg+HIG"拨开云端走了出来……。\n"
NOR, me);
            }
if( (string)me->query("family/family_name") == "昆仑山玉虚洞") {
message_vision(HIW"\n忽然一朵莲花降下，$N走了出来。 \n"
  NOR, me);
}
            if( (string)me->query("family/family_name")=="月宫") {
		message_vision(HIM"\n只听得半空中仙乐齐鸣，垂珠璎珞，一阵香风缥渺，异味芳馨氤氲，$N"+ridemsg+HIM"飘然而至…… \n"
NOR, me);
	}
			if( (string)me->query("family/family_name")=="盘丝洞") {
		message_vision(MAG"\n但见霞光万道，瑞彩千条，光婵灿烂，映目射眼，一道彩虹从天空划过，$N"+ridemsg+MAG"随彩虹飘然而至…… \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="五庄观") {
		message_vision(HIB"\n一阵清风吹来，$N"+ridemsg+HIB"从空中降落…… \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="大雪山") {
		message_vision(HIW"\n霎时间，大雪纷飞，雪花翩翩如雾卷云腾，冷气侵人，$N"+ridemsg+HIW"亦如晶莹剔透的雪花随风飘下…… \n"
 NOR, me);
	}
            if( (string)me->query("family/family_name")=="南海普陀山") {
		message_vision(HIY"\n刹那间祥云缭绕，佛光万丈，莲花万朵，络绎不断，$N"+ridemsg+HIY"踏着莲花宝座，徐徐降落尘间………\n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="东海龙宫") {
		message_vision(HIC"\n但见云光缥缈，半空中仿佛冲出一条水柱，$N"+ridemsg+HIC"从水柱上稳稳跳落地下……  \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="火云洞") {
		message_vision(RED"\n一团红色的烟雾涌了过来,$N"+ridemsg+RED"突然从里面蹦了出来. \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="蜀山剑派") {
		message_vision(HIC"\n一道蓝光闪过,$N"+ridemsg+HIC"从剑上跳了下来。 \n"
NOR, me);
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
moon        	->昆仑山月宫             penglai        ->蓬莱仙岛
lingtai         ->灵台方寸山        	 putuo      	->南海普陀山
xueshan	        ->大雪山寒冰谷           meishan        ->梅山灌江口
wuzhuang        ->万寿山五庄观

baoxiang	->宝象国		 pingding  	->平顶山
yalong    	->压龙山                 wuji           ->乌鸡国
chechi		->车迟国 		 tongtian	->通天河
jindou  	->金兜山 		 nuerguo	->女儿国
dudi   		->毒敌山 		 firemount	->火焰山
jilei    	->积雷山 		 jisaiguo	->祭赛国
jingjiling	->荆棘岭		 xiaoxitian	->小西天
zhuzi		->朱紫国		 qilin		->麒麟山
pansi		->盘丝岭		 biqiu		->比丘国 
qinghua		->清华庄		 wudidong       ->无底洞
qinfa           ->钦法国                 fengxian	->凤仙郡 
yinwu    	->隐雾山		 yuhua   	->玉华县 
baotou  	->豹头山		 zhujie  	->竹节山
jinping 	->金平府		 qinglong	->青龙山 
tianzhu 	->天竺国		 maoying 	->毛颖山 
huangfeng 	->黄风岭		 heifeng 	->黑风山
guanyin 	->观音院		 yingjian 	->鹰愁涧
kusong          ->枯松涧                 sisheng 	->四圣山庄
shuangcha 	->双叉岭		 yunzhan 	->云栈洞
lingshan        ->灵山                    

HELP
        );
        return 1;
}


