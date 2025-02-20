#include "UIManager.h"
#include "BackupManager.h"
#include <iostream>

DownloadThread UIManager::downloadThread;

void UIManager::setup(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");

    downloadThread.start("USD", [](nlohmann::json rates) {
        std::cout << "✅ Exchange rates updated!\n";
    });

    BackupManager::startBackup();
}

void UIManager::render(FinanceManager& financeManager) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("📊 Finance Tracker");

    if (ImGui::BeginTable("Transactions", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
        ImGui::TableSetupColumn("🗓 Date");
        ImGui::TableSetupColumn("📌 Category");
        ImGui::TableSetupColumn("💲 Amount");
        ImGui::TableHeadersRow();

        for (size_t i = 0; i < financeManager.getTransactions().size(); ++i) {
            const auto& transaction = financeManager.getTransactions()[i];
            ImGui::TableNextRow();
            
            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s", transaction.date.c_str());
            
            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%s", transaction.category.c_str());
            
            ImGui::TableSetColumnIndex(2);
            ImGui::Text("%.2f", transaction.amount);
        }

        ImGui::EndTable();
    }

    ImGui::Separator();

    static char date[20] = "2025-02-20";
    static char category[20] = "Food";
    static float amount = 0.0f;

    ImGui::InputText("Date", date, IM_ARRAYSIZE(date));
    ImGui::InputText("Category", category, IM_ARRAYSIZE(category));
    ImGui::InputFloat("Amount", &amount);

    if (ImGui::Button("➕ Add Transaction")) {
        financeManager.addTransaction({date, category, amount});
    }

    if (ImGui::Button("Backup Transactions")) {
        BackupManager::backupToServer();
    }

    if (ImGui::Button("⏪ Restore Transactions")) {
        std::vector<Transaction> restoredTransactions;
        BackupManager::restoreFromServer(restoredTransactions);
        for (const auto& transaction : restoredTransactions) {
            financeManager.addTransaction(transaction);
        }
    }

    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UIManager::shutdown() {
    downloadThread.stop();
    BackupManager::stopBackup();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
