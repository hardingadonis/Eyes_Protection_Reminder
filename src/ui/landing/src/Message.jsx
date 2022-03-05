import { useState, useEffect } from "react";

export default function Message({ message }) {
	const [text, setText] = useState("");
	const [nextText, setNextText] = useState("");

	useEffect(() => {
      setNextText(message)
		const interval = setInterval(() => {
			if (text == "") {
				clearInterval(interval);
				setText(nextText);
			}
			setText((prev) => prev.slice(0, prev.length - 1));
		}, 80);
	}, [message]);

	return <p>{text}</p>;
}
