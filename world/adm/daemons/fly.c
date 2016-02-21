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
                return notify_fail("ƒ„’˝‘⁄’Ω∂∑£¨∑…≤ªø™°£\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("ƒ„’˝√¶◊≈ƒÿ£¨√ªπ§∑ÚÃ⁄‘∆º›ŒÌ°£\n");
	if( !wizardp(me) && !environment(me)->query("outdoors") )
		return notify_fail("÷‹Œß√ª”–“ª∆¨‘∆£¨√ª∞Ï∑®Ã⁄‘∆º›ŒÌ°£\n");
	if( me->is_ghost() )
		return notify_fail("◊ˆ¡ÀπÌ¡À£¨æÕ¿œ µµ„∞…£°\n");
        if( !arg )
                return notify_fail("ƒ„“™∑…µΩƒƒ¿Ô»•£ø\n");
	if( me->query_temp("no_move") )
	    return notify_fail("ƒ„±ª∂®◊°¡À£¨ƒƒ¿Ô∑…µ√∆¿¥£°\n");

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
		< RANK_D->grade_dx(BLU "≥ı¡Ï√Óµ¿" NOR) )
	{
		message_vision(HIY
"$N∑‹¡¶Õ˚…œ“ªÃ¯£¨À∆∫ıœÎ∑…∆¿¥°£Ω·π˚¿Îµÿ≤ªµΩ»˝≥ﬂæÕ“ª∏ˆµπ‘‘¥–À§¡Àœ¬¿¥°£\n"
NOR, me);
		return notify_fail("ƒ„œ÷‘⁄ªπ≥ı¡Ï√Óµ¿∂ºÃ∏≤ª…œ£¨ƒƒ¿Ô∑…µ√∆¿¥°£\n");
	}

	if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
		< RANK_D->grade_fali(HIB "Ã⁄‘∆º›ŒÌ" NOR) )
	{
		message_vision(HIY
"$N∑‹¡¶Õ˚…œ“ªÃ¯£¨À∆∫ıœÎ∑…∆¿¥°£Ω·π˚¿Îµÿ≤ªµΩ»˝≥ﬂæÕ“ª∏ˆµπ‘‘¥–À§¡Àœ¬¿¥°£\n"
NOR, me);
		return notify_fail("ø¥¿¥“‘ƒ„µƒ∑®¡¶–ﬁŒ™ªπ≤ªƒ‹Ã⁄‘∆º›ŒÌ°£\n");
	}

	if( (int)me->query("mana") < 200 )
	{
		message_vision(HIY
"$N∑‹¡¶Õ˚…œ“ªÃ¯£¨À∆∫ıœÎ∑…∆¿¥°£Ω·π˚¿Îµÿ≤ªµΩ»˝≥ﬂæÕ“ª∏ˆµπ‘‘¥–À§¡Àœ¬¿¥°£\n"
NOR, me);
		return notify_fail("ƒ„ƒø«∞∑®¡¶≤ªπª≥‰”Ø°£\n");
	}


        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
                return
notify_fail("ƒ„œ÷‘⁄Õ∑ƒ‘≤ªÃ´«Â–—£¨µ±–ƒµÙœ¬¿¥À§À¿°£\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
                return
notify_fail("ƒ„œÎ∑…∆¿¥£¨ø… «ÃÂ¡¶À∆∫ı”–µ„≤ª÷ß°£\n");

        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        if(mana_cost > 0) mana_cost=0;

          if( (string)me->query("family/family_name") == "œ›ø’…ΩŒﬁµ◊∂¥") {
                  message_vision(HIB"÷ªº˚$NÀ´±€“ª’Ò,“ªπ…∫⁄—ÃΩ´$NΩÙΩÙπ¸◊°£¨µ´º˚º∏÷ªÚ˘Ú¥”∫⁄—Ã÷–Àƒ…¢∑…≥ˆ£¨∫⁄—Ã…¢æ°£¨$Nœ˚ ßµ√Œﬁ”∞Œﬁ◊Ÿ°≠°≠ \n\n"NOR, me);
}
           if( (string)me->query("family/family_name") == "Ω´æ¸∏Æ") {
      message_vision(HIR"$N¥È¥Ω¥µ¡À“ª∏ˆœÏ…⁄£¨“ª∆•…Òø•µƒ±¶¬ÌÀÊ…˘∂¯÷¡£¨$N◊›…Ì…œ¬Ì£¨æ¯≥æ∂¯»•°≠°≠ \n\n"NOR, me);
}
	if( (string)me->query("family/family_name") == "—÷¬ﬁµÿ∏Æ") {
		message_vision(CYN"$NÕ˘∫⁄∞µ¥¶“ª÷∏£¨÷ªº˚À˘÷∏÷Æ¥¶∑¬∑≥ˆœ÷“ª…»√≈£¨\n"+
"$N¥Û≤Ω◊ﬂ»Î£¨√≈“≤ÀÊ÷Æœ˚ ß°≠°≠ \n\n"NOR, me);
              }
	if( (string)me->query("family/family_name") == "∑Ω¥Á…Ω»˝–«∂¥") {
		message_vision(HIG"$NƒÌ∏ˆø⁄æ˜£¨ø⁄÷–ƒÓ∂Ø’Ê—‘£¨¥ÛΩ–“ª…˘£∫°∞ΩÓ∂∑‘∆£°°±£¨\n"+
"÷ªº˚ÃÏ…œΩµœ¬“ª∂‰∆ﬂ…´‘∆≤ £¨$N◊›…Ì‘æ…œ£¨∑…≥€∂¯»•......\n\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "‘¬π¨") {
		message_vision(HIM"$NÂ¸√ƒ“ª–¶£¨–¿»ª∆ŒË£¨ÀÊ◊≈“ª’Ûª®œ„£¨“—œ˚ ß‘⁄‘¬π‚÷–°≠°≠\n"NOR, me);
              }
		if( (string)me->query("family/family_name") == "≈ÃÀø∂¥") {
		message_vision(MAG"$N©ÕÛ«·∂∂£¨µ´º˚“ªµ¿≤ ∫Á¬‰¡Àœ¬¿¥,$NœÀ—¸«·∞⁄∆Æ»ª∂¯…œ,œºπ‚“ª…¡,≤ ∫Áœ˚ ßµƒŒﬁ”∞Œﬁ◊Ÿ°≠°≠\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ŒÂ◊Øπ€") {
		message_vision(HIB"$N¥Û–‰“ª∞⁄£¨∆Ωµÿ∆…Ì£¨÷ªº˚∑Á∆‘∆”ø£¨$N‘⁄ø’÷–¡¨Ã§≥ˆ«¨¿§∞ÀŒª£¨º∏≤ΩÃ§≥ˆ£¨…Ì–Œ“—»ªœ˚ ß°≠°≠\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "¥Û—©…Ω") {
		message_vision(HIW"$NÀÊ ÷“ªª”£¨÷ªº˚“ªÕ≈—©ŒÌπ¸◊°’Ê…Ì£¨–˝◊™∂¯»•°≠°≠ \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ƒœ∫£∆’Õ”…Ω") {
		message_vision(HIY"$Nø⁄÷–ƒÓ◊≈∑∫≈£¨Ω≈œ¬…˝∆“ª∂‰¡´ª®±¶◊˘£¨ª∫ª∫¿Îµÿ∑…»•°≠°≠  \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "∂´∫£¡˙π¨") {
		message_vision(HIC"$Nø⁄“°…Ì“ª±‰£¨œ÷≥ˆ‘≠–Œ£¨’˝ «“ªÃı…Ò¡˙£¨ÀÊº¥¥©‘∆∂¯»•°≠°≠ \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ª‘∆∂¥") {
              message_vision(RED"$Nø⁄ƒÌ∏ˆø⁄æ˜£¨ø⁄÷–ƒÓ∂Ø’Ê—‘,Õª»ª°∞∫‰°±µÿ√∞∆“ªÕ≈∫ÏŒÌ,$NÀÊº¥“˛»Î∫ÏŒÌ÷–°£\n"NOR, me);
              }
         if( (string)me->query("family/family_name") == " Ò…ΩΩ£≈…") {
             message_vision(HIC"$Nø⁄ƒÌ∏ˆø⁄æ˜£¨»”≥ˆ“ª∞—±¶Ω££¨$N∑…≥€∂¯…œ£¨“ª’–°∏”˘Ω£∑…––°πœÚ‘∂∑Ω∑…»•°£°£°£°£\n"NOR, me);
     }
 

        me->add("mana", mana_cost);

//      if(arg=="stone") loc="/d/4world/entrance";^M
        if(arg=="stone") loc="/d/dntg/hgs/entrance";
        else if(arg=="kaifeng") loc="/d/kaifeng/tieta";
        else if(arg=="moon") loc="/d/moon/ontop2";
        else if(arg=="lingtai") loc="/d/lingtai/gate";
        else if(arg=="putuo") loc="/d/nanhai/gate";
        else if(arg=="changan") loc="/d/city/center";
        else if(arg=="sky") loc="/d/dntg/sky/nantian";
	 else if(arg=="wuzhuang") loc="/d/qujing/wuzhuang/gate";
	 else if(arg=="meishan") loc="/d/meishan/erlangwai";
        else if(arg=="wudang") loc="/d/wudang/xuanyuegate";
              else if(arg=="shushan") loc="/d/shushan/road1";
              else if(arg=="penglai") {
		if(!(map=present("eastsea map", me)) && !wizardp(me)) {
			write("ƒ„‘⁄ÃÏ…œ◊™¡À∞ÎÃÏ“≤≤ª÷™∏√Õ˘ƒ«±ﬂ∑…°£°£°£\n");
			message_vision("\n$N ßÕ˚µÿ¥”‘∆…œÃ¯¡Àœ¬¿¥£°\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="’≈" ){
			write("ƒ„‘⁄ÃÏ…œ◊™¡À∞ÎÃÏ“≤≤ª÷™∏√Õ˘ƒ«±ﬂ∑…°£°£°£\n");
                        message_vision("\n$N ßÕ˚µÿ¥”‘∆…œÃ¯¡Àœ¬¿¥£°\n", me);
                        return 1;
                        }
//		write("ƒ„º›◊≈œÈ‘∆œÚ∂´±ﬂ∫£÷–∑…»•°£°£°£\n\n");
		loc="/d/penglai/penglai";
	}
	else if(arg=="xueshan") {
		if(!(map=present("xueshan map", me)) && !wizardp(me)) {
			write("ƒ„‘⁄ÃÏ…œ◊™¡À∞ÎÃÏ“≤≤ª÷™∏√Õ˘ƒ«±ﬂ∑…°£°£°£\n");
			message_vision("\n$N ßÕ˚µÿ¥”‘∆…œÃ¯¡Àœ¬¿¥£°\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="’≈" ){
                        write("ƒ„‘⁄ÃÏ…œ◊™¡À∞ÎÃÏ“≤≤ª÷™∏√Õ˘ƒ«±ﬂ∑…°£°£°£\n");
                        message_vision("\n$N ßÕ˚µÿ¥”‘∆…œÃ¯¡Àœ¬¿¥£°\n", me);
                        return 1;
                        }
//		write("ƒ„º›◊≈œÈ‘∆œÚ¥Û—©…Ω∑…»•°£°£°£\n\n");
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
		/*
		if (me->query("obstacle/nuerguo")!="done" && !wizardp(me)){
			write("\n“ª’Û∑Á∞—ƒ„∂´µπŒ˜Õ·µÿ¥µ¡Àªÿ¿¥£°\n");
			write("ø¥—˘◊”∑…≤ªπ˝»•°£\n");
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
		}else if(arg=="huangfeng"){
         	loc = "/d/qujing/huangfeng/huangfeng.c";
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
                write("\n\nµΩ¡À£°ƒ„∞¥œ¬‘∆Õ∑Ã¯¡Àœ¬¿¥°£\n");
                write("ﬂ◊£ø£Æ£Æ£Æ‘ı√¥ªπ‘⁄‘≠¿¥µƒµÿ∑Ω£ø\n");
                return 1;
        }

	if (! loc)
		return 1;
		
	// mon /10/18/98
	if(MISC_D->random_capture(me,0,1)) return 1;

	if (ridee = me->ride()) {
	  ridemsg = ridee->query("ride/msg")+"◊≈"+ridee->name();
	  ridee->move(loc);
	}  
	else  
	  ridemsg = "";
	                                            	
	me->move(loc);
//       write("\n\nµΩ¡À£°ƒ„∞¥œ¬‘∆Õ∑Ã¯¡Àœ¬¿¥°£\n");

          if( (string)me->query("family/family_name") == "œ›ø’…ΩŒﬁµ◊∂¥") {
message_vision(HIB"\n∫ˆ»ªº‰πŒ∆“ª’Û“ı∑Á£¨º∏÷ªÚ˘Ú≥À∑Á∑…¿¥£¨µ´º˚º∏÷ªÚ˘Ú∫œŒ™“ª¥¶,°∞≈æ°±µƒ“ªπ…∫⁄—Ã…˝∆,$N"+ridemsg+HIB"¥”∫⁄—Ã÷–◊ﬂ¡À≥ˆ¿¥°≠°≠ \n"
  NOR, me);
}
           if( (string)me->query("family/family_name") == "Ω´æ¸∏Æ") {
   message_vision(HIB"\n ’∂˙”˚¡˚µƒ“ª…˘£∫°∞±æΩ´‘⁄¥À£°°±£¨$N“—¿¥µΩ¥Ûº“—€«∞°£\n"
  NOR, me);
}
	if( (string)me->query("family/family_name")=="—÷¬ﬁµÿ∏Æ") {
		message_vision(CYN"\n“ı”∞÷–¥µ∆“ª’Û¿‰∑Á£¨∞ÈÀÊ◊≈¿‰…≠…≠µƒ–¶…˘£¨$N"+ridemsg+CYN"»Á˜Œ˜»∞„¥”∫⁄∞µ÷–≥ˆœ÷°≠°≠ \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="∑Ω¥Á…Ω»˝–«∂¥") {
		message_vision(HIG"\n÷ªº˚ÃÏº‰œºπ‚…¡À∏£ ø’÷–∆Æ¬‰“ª∂‰∆ﬂ≤ œÈ‘∆£¨$N"+ridemsg+HIG"≤¶ø™‘∆∂À◊ﬂ¡À≥ˆ¿¥°≠°≠°£\n"
NOR, me);
            }
            if( (string)me->query("family/family_name")=="‘¬π¨") {
		message_vision(HIM"\n÷ªº˚“ªµ¿‘¬π‚»˜‘⁄ƒ„√Ê«∞£¨»·»·µƒ£¨¿‰¿‰µƒ£¨$N"+ridemsg+HIM"¥”÷–∆Æ»ª∂¯÷¡°≠°≠ \n"
NOR, me);
	}
			if( (string)me->query("family/family_name")=="≈ÃÀø∂¥") {
		message_vision(MAG"\nµ´º˚“ªµ¿≤ ∫Á¥”ÃÏø’ªÆπ˝£¨$N"+ridemsg+MAG"ÀÊ≤ ∫Á∆Æ»ª∂¯÷¡°≠°≠ \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="ŒÂ◊Øπ€") {
		message_vision(HIB"\n“ª’Û«Â∑Á¥µ¿¥£¨$N"+ridemsg+HIB"¥”ø’÷–Ωµ¬‰°≠°≠ \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="¥Û—©…Ω") {
		message_vision(HIW"\nˆÆ ±º‰£¨¥Û—©∑◊∑…£¨$N"+ridemsg+HIW"“‡»Áæß”®ÃﬁÕ∏µƒ—©ª®ÀÊ∑Á∆Æœ¬°≠°≠ \n"
 NOR, me);
	}
            if( (string)me->query("family/family_name")=="ƒœ∫£∆’Õ”…Ω") {
		message_vision(HIY"\nÃÏ±ﬂ«ß∂‰∆ﬂ≤ œÈ‘∆œ‘œ÷,…≤ƒ«º‰∑π‚ÕÚ’…£¨£¨$N"+ridemsg+HIY"Ã§◊≈¡´ª®±¶◊˘£¨–Ï–ÏΩµ¬‰≥æº‰°≠°≠°≠\n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="∂´∫£¡˙π¨") {
		message_vision(HIC"\n∞Îø’÷–∑¬∑≥Â≥ˆ“ªÃıÀÆ÷˘°±£¨$N"+ridemsg+HIC"¥”ÀÆ÷˘…œŒ»Œ»Ã¯¬‰µÿœ¬°≠°≠  \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")=="ª‘∆∂¥") {
		message_vision(RED"\n“ªÕ≈∫Ï…´µƒ—ÃŒÌ”ø¡Àπ˝¿¥,$N"+ridemsg+RED"Õª»ª¥”¿Ô√Ê±ƒ¡À≥ˆ¿¥. \n"
NOR, me);
	}
            if( (string)me->query("family/family_name")==" Ò…Ω") {
		message_vision(HIC"\n“ªµ¿¿∂π‚…¡π˝,$N"+ridemsg+HIC"¥”Ω£…œÃ¯¡Àœ¬¿¥°£ \n"
NOR, me);
	}

                 return 1;
}

int help(object me)
{
        write(@HELP
÷∏¡Ó∏Ò Ω : fly|fei [ƒøµƒµÿ]

µ±ƒ„µƒµ¿––∫Õ∑®¡¶∏ﬂ«ø ±£¨ƒ„ø…“‘Ã⁄‘∆º›ŒÌ°£

ƒø«∞ƒ„ø…“‘∑…µΩµƒµÿ∑Ω£∫
changan         ->≥§∞≤≥«                 kaifeng        ->ø™∑‚≥«
stone           ->ª®π˚…Ωœ… Ø             sky            ->ƒœÃÏ√≈
moon      	->¿•¬ÿ…Ω‘¬π¨             penglai        ->≈Ó¿≥œ…µ∫
lingtai         ->¡ÈÃ®∑Ω¥Á…Ω    	 putuo     	->ƒœ∫£∆’Õ”…Ω
xueshan	        ->¥Û—©…Ω∫Æ±˘π»           meishan        ->√∑…Ωπ‡Ω≠ø⁄
wuzhuang        ->ÕÚ Ÿ…ΩŒÂ◊Øπ€

baoxiang	->±¶œÛπ˙		 pingding  	->∆Ω∂•…Ω
yalong    	->—π¡˙…Ω 		 wuji           ->Œ⁄º¶π˙
chechi		->≥µ≥Ÿπ˙ 		 tongtian	->Õ®ÃÏ∫”
jindou  	->Ω∂µ…Ω 		 nuerguo	->≈Æ∂˘π˙
dudi   		->∂æµ–…Ω 		 firemount	->ª—Ê…Ω
jilei    	->ª˝¿◊…Ω 		 jisaiguo	->º¿»¸π˙
jingjiling	->æ£º¨¡Î		 xiaoxitian	->–°Œ˜ÃÏ
zhuzi		->÷Ï◊œπ˙		 qilin		->˜Ë˜Î…Ω
pansi		->≈ÃÀø¡Î		 biqiu		->±»«π˙ 
qinghua		->«Âª™◊Ø		 wudidong       ->Œﬁµ◊∂¥
qinfa           ->«’∑®π˙		 fengxian	->∑Ôœ…ø§ 
yinwu    	->“˛ŒÌ…Ω		 yuhua   	->”Òª™œÿ 
baotou  	->±™Õ∑…Ω		 zhujie  	->÷ÒΩ⁄…Ω
jinping 	->Ω∆Ω∏Æ		 qinglong	->«‡¡˙…Ω 
tianzhu 	->ÃÏÛ√π˙		 maoying 	->√´”±…Ω 
lingshan	->¡È…Ω                   

HELP
        );
        return 1;
}

