//
// Created by fatzzx on 23/06/23.
//

#ifndef DISCORD_BOT_HELLO_H
#define DISCORD_BOT_HELLO_H

#include "discord_bot.h"

void handleHelloCommand(const dpp::slashcommand_t& event){
    std::string username = event.command.usr.username;
    std::string  response = "Hello " + username + "!";
    event.reply(response);
}

#endif //DISCORD_BOT_HELLO_H
