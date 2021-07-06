module.exports = {
  siteMetadata: {
    siteTitle: "『詳解セキュリティコンテスト』",
    defaultTitle: "『詳解セキュリティコンテスト』",
    siteTitleShort: "『詳解セキュリティコンテスト』",
    siteDescription:
      "書籍『詳解セキュリティコンテスト』の補助情報や配布ファイルを提供するページです。",
    siteUrl: "https://ctfbook.github.io/2nd",
    siteAuthor: "『詳解セキュリティコンテスト』著者",
    siteImage: "/banner.png",
    siteLanguage: "ja",
    themeColor: "#8257E6",
    basePath: "/",
  },
  pathPrefix: "/2nd",
  flags: { PRESERVE_WEBPACK_CACHE: true },
  plugins: [
    {
      resolve: "@rocketseat/gatsby-theme-docs",
      options: {
        configPath: "src/config",
        docsPath: "src/docs",
        repositoryUrl: "https://github.com/ctfbook/2nd",
        baseDir: "",
      },
    },
    "gatsby-plugin-sitemap",
    "gatsby-plugin-remove-trailing-slashes",
    {
      resolve: "gatsby-plugin-canonical-urls",
      options: {
        siteUrl: "https://ctfbook.github.io/2nd",
      },
    },
    "gatsby-plugin-offline",
    {
      resolve: "gatsby-plugin-typegen",
      options: {
        outputPath: `src/@types/gatsby-types.d.ts`,
      },
    },
  ],
};
