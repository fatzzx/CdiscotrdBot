#ifndef DISCORD_BOT_WAIFU_H
#define DISCORD_BOT_WAIFU_H

#include "discord_bot.h"
#include <future>
#include <regex>

std::string extractUrlFromJson(const std::string& jsonString) {
    std::regex urlRegex(R"(https:\/\/.*?\.jpg)");
    std::smatch urlMatch;

    if (std::regex_search(jsonString, urlMatch, urlRegex)) {
        return urlMatch[0].str();
    }

    return "";
}

std::string getApiResponse() {
    std::string apiResponse;

    httplib::Client httpClient("api.waifu.pics");

    auto response = httpClient.Get("/sfw/waifu");

    if (response && response->status == 200) {
        apiResponse = response->body;
    } else {
        std::cout << "Erro na requisição" << std::endl;
    }

    return apiResponse;
}

void handleGeneralWaifuApiCommand(const dpp::slashcommand_t& event) {
    std::future<std::string> futureApiResponse = std::async(std::launch::async, getApiResponse);

    std::string apiResponse = futureApiResponse.get();

    std::string imageUrl = extractUrlFromJson(apiResponse);

    dpp::embed embed = dpp::embed()
            .set_title("Waifu")
            .set_color(dpp::colours::pink)
            .set_image(imageUrl)
            .set_footer(dpp::embed_footer().set_text("creep").set_icon("https://avatars.githubusercontent.com/u/112991044?v=4"))
            .set_timestamp(time(0));

    dpp::message message(event.command.channel_id, embed);
    event.reply("aaaaa");
    event.reply(message);
}

#endif // DISCORD_BOT_WAIFU_H
