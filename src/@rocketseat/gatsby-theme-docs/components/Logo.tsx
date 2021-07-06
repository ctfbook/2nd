import React from "react";
import logoImg from "../../../assets/logo.png";

const Logo: React.FC = (props) => {
  return (
    <img
      src={logoImg}
      alt="『詳解セキュリティコンテスト』"
      style={{
        width: 250,
        height: 115,
      }}
    />
  );
};

export default Logo;
