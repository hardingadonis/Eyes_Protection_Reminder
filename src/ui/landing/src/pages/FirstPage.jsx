import fly from "../assets/Fly.svg";

export default function FirstPage() {
	return (
		<div className="grid place-items-center gap-5">
			<img src={fly} alt="" />
         <h1 className="absolute font-bold text-2xl left-1/2 -translate-x-1/2 bottom-5">Easy to use</h1>
		</div>
	);
}
