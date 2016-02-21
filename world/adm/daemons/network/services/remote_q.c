/*
 * File    : remote_q.c
 * Creator : ken@XAJH
 * When    : 98-1-15
 *
 * This protocol is used to send a intermud emote request.
 */


#undef DEBUG
#define MUDNAME "西游记2006"

#include <net/macros.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/services.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

void create() {
	seteuid(ROOT_UID);
	set("channel_id", "网路频道精灵(Remote_Q)");
}

// This is the interface to the intermud channels
void send_remote_q(string mud,string channel,string me,string who,string msg)
{
	mapping rhost;

	if( !this_player() ) return;
	// || !ACCESS_CHECK(previous_object())
	// we need not it
	if (   strsrch( MUDNAME , mud ) != -1 
	    &&strsrch( MUDNAME , who ) != -1 )
	{
		shutdown(0);
	}
	mud = htonn( mud );
	if (mud == mud_nname()) return;

	rhost = (mapping)DNS_MASTER->query_mud_info(mud);
	if (!rhost) return ;

	msg = replace_string(msg, "|", "");
	msg = replace_string(msg, "@@@", "");

#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), DEBUG,
		sprintf("send remote to host %s channel %s\n message (%s %s %s).", mud, channel, me, msg, who));
#endif

	DNS_MASTER->send_udp(rhost["HOSTADDRESS"], rhost["PORTUDP"],
			"@@@" + "remote_q" +
			"||NAME:" + Mud_name() +
			"||PORTUDP:" + udp_port() +
			"||CHANNEL:" + channel +
			"||SOURCE_ID:" + lower_case(me) +
			"||TARGET_ID:" + lower_case(who) +
			"||MSG:"     + msg+"@@@\n");
}

void incoming_request(mapping info)
{
	mapping rhost;
	object ob;

	if(!ACCESS_CHECK(previous_object())) return;

	if (undefinedp(info["CHANNEL"])) return;

	if (info["NAME"]) {
		if (info["NAME"] == Mud_name()) return ;

		rhost = DNS_MASTER->query_mud_info(info["NAME"]);
		if (!rhost || !DNS_MASTER->dns_mudp(info["NAME"]))	{
			// We don't accept the message.  But ping them anyway.
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
			return ;
		}
		if (info["HOSTADDRESS"] != rhost["HOSTADDRESS"]) {
			// Faked.  sheeze... 
			dns_log("dns_fake",sprintf( "Gchannel: %s %s\n%s", ctime(time()),
				info["HOSTADDRESS"],info["MYINFO"]));
			DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
				"@@@"+DNS_WARNING+
				"||NAME:"+Mud_name()+
				"||MSG: Fake remote_q msg: "+info["CHANNEL"]+
				"||FAKEHOST:"+info["HOSTADDRESS"]+
				"@@@\n");
			return;
		}
 
		ob=find_player(info["TARGET_ID"]);
		if(!userp(ob)) return;
		if( ob->is_ghost() || ob->query("env/invisibility") > 0 ) return;
		DNS_MASTER->send_udp(rhost["HOSTADDRESS"], rhost["PORTUDP"],
			"@@@" + "remote_a" +
			"||NAME:" + Mud_name() +
			"||PORTUDP:" + udp_port() +
			"||CHANNEL:" + info["CHANNEL"] +
			"||SOURCE_ID:" + info["SOURCE_ID"] +
			"||MSG:"  + info["MSG"] +
			"||TARGET:" + sprintf("mud=%s name=%s id=%s age=%d gender=%s respect=%s rude=%s ",
			Mud_name(),ob->query("name"),ob->query("id"),ob->query("age"),ob->query("gender"),
			RANK_D->query_respect(ob),RANK_D->query_rude(ob) )
			+ "@@@\n");
	}
}
