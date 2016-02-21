// modi by tomcat 

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
  "蜀山剑派",
  "大唐皇宫",
});

void create()
{
        seteuid(getuid());
        set("name","");
        remove_call_out("choose_npc");
        call_out("choose_npc",2);
}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
                    
        j = random(sizeof(families));
        k = random(sizeof(families));
        newob = new(__DIR__"fei");
        newob->set("target",families[k]);
        newob->invocation( j );
        reset_eval_cost();
        
        switch(families[k])
        {
                case "方寸山三星洞":
                        m_name="菩提老祖(Master puti)";//
                        newob->carry_object("/d/npc/obj/shield");
                        break;
                case "月宫":
                        m_name="西王母(Xi wangmu)";//
                        newob->carry_object("/d/npc/obj/xiuhuaxie");
                        break;
                case "阎罗地府":
                        m_name="地藏王菩萨(Dizang pusa)";//
                        newob->carry_object("/d/npc/obj/stick");
                        break;
                case "陷空山无底洞":
                        m_name="玉鼠精(Yu shu)";//
                        newob->carry_object("/d/npc/obj/pifeng");
                        break;
                case "将军府":
                        m_name="白发老人(lao ren)";//
                        newob->carry_object("/d/npc/obj/mace");
                           break;
                case "火云洞":
                        m_name="黄飞虎(huang feihu)";//
                        newob->carry_object("/d/npc/obj/spear");
                        break;
                case "大雪山":
                        m_name="大鹏明王(Dapeng mingwang)";//
                        newob->carry_object("/d/npc/obj/qin");
                        break;
                case "五庄观":
                        m_name="镇元大仙(Zhenyuan daxian)";
                        newob->carry_object("/d/npc/obj/sword");
                        break;
                case "南海普陀山":
                        m_name="观音菩萨(Guanyin pusa)";//
                        newob->carry_object("/d/npc/obj/shoes");
                        break;
                case "东海龙宫":
                        m_name="敖广(Ao guang)";//
                        newob->carry_object("/d/npc/obj/hammer");
                        break;
                case "盘丝洞":
                        m_name="紫霞仙子(zixia xianzi)";//
                        newob->carry_object("/d/npc/obj/jing");
                        break;
                case "蜀山剑派":
                        m_name="蜀山剑圣(jian sheng)";//
                        newob->carry_object("/d/npc/obj/armor");
                        break;
                case "大唐皇宫":
                        m_name="唐太宗(tang taizong)";//
                        newob->carry_object("/d/npc/obj/magua");
                        break;
        }
          message("system",HIG"【"+HIR+"江湖追杀令"+HIG+"】"+HIW+m_name+HIG"：现有蒙面飞贼盗走本门镇山之宝，"+"现已逃窜至"+families[j]+"一带,杀无赦。\n"NOR,users());
          remove_call_out("choose_npc");
          call_out("choose_npc",600);
       
}
