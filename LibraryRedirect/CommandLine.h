#pragma once

#include <string>
#include <CLI/CLI.hpp>

class CommandLine
{
	CLI::App m_app;

	std::string m_documentsPath;
	std::string m_downloadsPath;
	std::string m_desktopPath;

public:
	CommandLine(std::string binaryFilename);
	CommandLine(CommandLine&) = delete;

	inline void PrintHelp(std::ostream &stream)
	{
		stream << m_app.help();
	}

	inline void Parse(int argc, char* argv[])
	{
		m_app.parse(argc, argv);
	}

	inline std::string GetDocumentsPath() const
	{
		return m_documentsPath;
	}

	inline std::string GetDesktopPath() const
	{
		return m_desktopPath;
	}

	inline std::string GetDownloadsPath() const
	{
		return m_downloadsPath.c_str();
	}

	inline bool HasDocumentsPath() const
	{
		return !m_documentsPath.empty();
	}

	inline bool HasDesktopPath() const
	{
		return !m_desktopPath.empty();
	}

	inline bool HasDownloadsPath() const
	{
		return !m_downloadsPath.empty();
	}

	inline bool Anything() const
	{
		return HasDesktopPath() || HasDocumentsPath() || HasDownloadsPath();
	}
};

