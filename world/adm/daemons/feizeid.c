// modi by tomcat 
#include <tomud.h>
#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "大雪山",
  "方寸山三星洞",
  "月宫",
  "南海普陀山",
  "阎罗地府",
  "盘丝洞",
  "将军府",
  "东海龙宫",
  "陷空山无底洞",
  "五庄观",
  "火云洞",
  "蜀山派",
  "大唐皇宫",
  "乌鸡国",
  "宝象国",
  "天竺国",
  "女儿国",
  "玉华县",
});

string *feizei=({"fei-putuo","fei-moon","fei-wzg","fei-shushan","fei-hyd",
    "fei-fangcun","fei-hell","fei-jjf","fei-pansi","fei-dragon", "fei-xueshan",
     "fei-wudidong",});

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "内存精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "\n门派挑衅系统已经启动。\n"); 
        set("name","");
        remove_call_out("choose_npc");
        call_out("choose_npc",10);
}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
        string smp;
        smp  = "镇山之宝";
                   
        j = random(sizeof(families));
        k = random(sizeof(families));
        newob = new("/d/npc/"+feizei[random(sizeof(feizei))]);
        newob->set("target",families[k]);
        newob->invocation( j );
        reset_eval_cost();
        
        switch(families[k])
        {
                case "方寸山三星洞":
                        m_name="菩提老祖";//
                        newob->carry_object("/d/npc/obj/stick");
						smp = "霹雳棍";
                        break;
                case "月宫":
                        m_name="西王母";//
                        newob->carry_object("/d/npc/obj/windyshoes");
                                                smp = "疾风靴";
                        break;
                case "阎罗地府":
                        m_name="地藏王菩萨";//
                        newob->carry_object("/d/npc/obj/whip2");
						smp = "烈火鞭";
                        break;
                case "陷空山无底洞":
                        m_name="玉鼠精";//
                        newob->carry_object("/d/npc/obj/blade");
						smp = "妖刀";
                        break;
                case "将军府":
                        m_name="白发老人";//
                        newob->carry_object("/d/npc/obj/axe");
						smp = "鬼斧";
                           break;
                case "火云洞":
                        m_name="黄飞虎";//
                        newob->carry_object("/d/npc/obj/spear");
						smp = "火魔枪";
                        break;
                case "大雪山":
                        m_name="大鹏明王";//
                        newob->carry_object("/d/npc/obj/qin");
						smp = "天魔琴";
                        break;
                case "五庄观":
                        m_name="镇元大仙";
                        newob->carry_object("/d/npc/obj/dragonxiao");
                        smp = "盘龙箫";
                        break;
                case "南海普陀山":
                        m_name="文殊菩萨";//
                        newob->carry_object("/d/npc/obj/staff");
						smp = "七宝禅杖";
                        break;
                case "东海龙宫":
                        m_name="妈祖娘娘";//
                        newob->carry_object("/d/npc/obj/fork");
						smp = "神水叉";
                        break;
                case "盘丝洞":
                        m_name="紫霞仙子";//
                        newob->carry_object("/d/npc/obj/necklace");
						smp = "血玲珑";
                        break;
                case "蜀山派":
                        m_name="蜀山剑圣";//
                        newob->carry_object("/d/npc/obj/armor");
						smp = "黄金战甲";
                        break;
                case "大唐皇宫":
                        m_name="唐太宗";//
                        newob->carry_object("/d/npc/obj/mace");
                        smp = "除魔锏";
                        break;
                case  "乌鸡国":
                        m_name="乌鸡国国王";//
                        newob->carry_object("/d/npc/obj/kui");
                        smp = "紫金冠";
                        break;
                case  "宝象国":
                        m_name="宝象国国王";//
                        newob->carry_object("/d/npc/obj/magua");
                        smp = "天蝉衣";
                        break;
                case  "天竺国":
                        m_name="天竺国国王";//
                        newob->carry_object("/d/npc/obj/pifeng");
                        smp = "白狐披风";
                        break;
                case  "女儿国":
                        m_name="女儿国国王";//
                        newob->carry_object("/d/npc/obj/jing");
                        smp = "封虹巾";
                        break;
                case  "玉华县":
                        m_name="玉华县县令";//
                        newob->carry_object("/d/npc/obj/shield");
                        smp = "乾坤盾";
                        break;
                        
        }
// message("system",HIW"【"+HIR+"天庭快报"+HIW+"】"+HIY+m_name+NOR"：现有蒙面飞贼盗走"+smp+"，现已逃窜至"+families[j]+"一带。\n"NOR,users());

message("system",PTEXT(HIY"【"+NOR+"天庭通缉令"+HIY+"】"+NOR+"千里眼"+NOR"：昨夜一妖怪盗走"+HIC+m_name+HIW+smp+NOR"，现正在"+HIM+families[j]+NOR"一带逃窜。\n"NOR),users());remove_call_out("choose_npc");
          call_out("choose_npc",600);
       
}


