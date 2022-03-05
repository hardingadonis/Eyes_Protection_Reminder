import { Transition } from "@headlessui/react";

import dashboard from "../assets/Dashboard.svg";
import close from '../assets/Close.svg'

export default function FirstPage() {
	return (
		<div className="wrapper">
			<div className="rect  opacity-0 animate-1 w-52 h-24 top-16 left-20">
				<div className="wrapper">
					<div className="relative top-5 left-3">
						<div className="item w-12 h-4"></div>
						<div className="relative top-2 left-20">
							<div className="item  w-24 h-[2px] top-0 left-0"></div>
							<div className="item animate-slide-1 left-5 w-2 h-2 top-0 -translate-y-[3px] bg-white"></div>
						</div>
					</div>
					<div className="relative top-[54px] left-3">
						<div className="item w-12 h-4"></div>
						<div className="relative top-2 left-20">
							<div className="item w-24 h-[2px] top-0 left-0"></div>
							<div className="item animate-slide-2 left-16 w-2 h-2 top-0 -translate-y-[3px] bg-white"></div>
						</div>
					</div>
				</div>
			</div>
			<div className="rect  opacity-0 animate-2 w-48 h-[57px] top-52 left-40">
				<div className="item w-12 h-[13px] top-[22px] left-3"></div>
				<div className="relative top-5 left-20">
					<div className="item animate-choose-1 w-[27px] h-[18px]"></div>
					<div className="item animate-choose-2 w-[27px] h-[18px] left-9"></div>
					<div className="item animate-choose-3 w-[27px] h-[18px] left-[72px]"></div>
				</div>
			</div>
			<div className="rect  opacity-0 animate-3 w-44 h-24 top-20 left-80">
				<div className="item w-12 h-[13px] top-[15px] left-5"></div>
				<div className="relative top-[13px] left-24">
					<div className="item animate-pulse w-12 h-4"></div>
					<div className="relative top-5">
						<div className="item animate-vertical-choose-1 relative w-12 h-4 rounded-bl-none rounded-br-none"></div>
						<div className="item animate-vertical-choose-2 relative rounded-none w-12 h-4"></div>
						<div className="item animate-vertical-choose-3 relative w-12 h-4 rounded-tl-none rounded-tr-none"></div>
					</div>
				</div>
			</div>
			<img
				className="absolute  opacity-0 animate-4 w-52 h-24 top-52 left-96 "
				src={dashboard}
				alt=""
			/>
			<div className="rect  opacity-0 animate-5 w-56 h-24 top-[90px] left-[520px] p-3">
				<div className="bg-gray-900 w-full h-full px-[10px] py-[5px] grid gap-1">
					<p className="text-[9px] flex justify-between">Eyes Protection Reminder <img src={close} alt="" /></p>
					<hr />
					<p className="text-[9px] text-none">
						Time to take a rest my dear <span className="text-red-500">❤</span> Drop your glasses, look around..
						Is there anything make you interesting?
					</p>
				</div>
			</div>
         <h1 className="absolute font-bold text-2xl left-1/2 -translate-x-1/2 bottom-5">Easily customize in your own way</h1>
		</div>
	);
}
