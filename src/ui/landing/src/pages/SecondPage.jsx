import work from "../assets/Work.svg";

export default function FirstPage() {
	return (
		<div className="grid place-items-center gap-10 mt-5">
			<img src={work} alt="" />
         <h1 className="absolute font-bold text-2xl left-1/2 -translate-x-1/2 bottom-5">Ultimately focus on your work</h1>
		</div>
	);
}
