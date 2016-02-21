// modi by xintai 2/15/01

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "大雪山",
  "方寸山三星洞",
  "昆仑山玉虚洞",
  "南海普陀山",
  "阎罗地府",
  "盘丝洞",
  "将军府",
  "东海龙宫",
  "五庄观",
  "陷空山无底洞",
  "火云洞",
  "三界散仙",
  "月宫",
  "蜀山派",
});

void create()
{
        seteuid(getuid());
        set("name","");
        remove_call_out("choose_mpc");
        call_out("choose_mpc",10);
}

void choose_mpc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
        list = users();
        i = sizeof(list);

        if (i < 5){
        remove_call_out("choose_mpc");
        call_out("choose_mpc",120);
        return;
        }

        j = random(sizeof(families));
        k = random(sizeof(families));
        while( i-- ) {
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j]
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 10000 )

                {
                newob = new(__DIR__"npc");
                newob->set("target",families[k]);
                if(newob->invocation(list[i], k ))
                ppl++;
                else
                destruct(newob);
                }
        }
        
        reset_eval_cost();
        
        switch(families[k])
        {
                case "方寸山三星洞":
                        m_name="菩提老祖(Master puti)";//
                        break;
                case "昆仑山玉虚洞":
                        m_name="广成子(Guang chengzi)";//
                        break;
                case "阎罗地府":
                        m_name="地藏王菩萨(Dizang pusa)";//
                        break;
                case "陷空山无底洞":
                        m_name="碧鼠精(Bi shu)";//
                        break;
                case "将军府":
                        m_name="程咬金(Cheng yaojin)";//
                        break;
                case "火云洞":
                        m_name="牛魔王(Niu mowang)";//
                        break;
                case "大雪山":
                        m_name="孔雀公主(Kongque gongzhu)";//
                        break;
                case "五庄观":
                        m_name="镇元大仙(Zhenyuan daxian)";
                        break;
                case "南海普陀山":
                        m_name="善财童子(Shancai tongzi)";//
                        break;
                case "东海龙宫":
                        m_name="敖广(Ao guang)";//
                        break;
                case "盘丝洞":
                        m_name="紫霞仙子(Zixia xianzi)";//
                        break;
                case "蜀山派":
                        m_name="李逍遥(Li xiaoyao)";//
                        break;
                case "三界散仙":
                        m_name="中山夫子(Zhongshan fuzi)";//
                       break;
		case "月宫":
                        m_name="西王母(Xi wangmu)";//
                       break;
        }
        if (ppl)
        {
        if (j != k)
        message("system",HIW"〖"+HIR+families[k]+HIW+"〗"+HIY+m_name+CYN"：有"+HIM+chinese_number(ppl)+CYN"名"+HIW+families[j]+CYN"刺客正在本门滋事，众弟子速回护法。\n"NOR,users());
        else
        message("system",HIW"〖"+HIR+families[k]+HIW+"〗"+HIY+m_name+CYN"：本派"+HIM+chinese_number(ppl)+CYN"名不孝弟子，欺师灭祖，众弟子速回护法。\n"NOR,users());
        remove_call_out("choose_mpc");
        call_out("choose_mpc",250);
        }
        else
        {
        message("system",HIG"〖大唐盛世〗太平公主「唉」的一声叹了口气。\n"NOR,users());
        message("system",HIG"〖大唐盛世〗太平公主(taiping gongzhu)：长安月下,一壶清酒,一树梨花!\n"NOR,users());
        remove_call_out("choose_mpc");
        call_out("choose_mpc",60);
        }
}


