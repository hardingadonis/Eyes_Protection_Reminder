import logo from '../assets/Logo.svg'

export default function Home() {
   return <div className='grid place-items-center gap-7 mt-16'>
      <img src={logo} alt="" />
      <h1 className='font-bold text-5xl'>Eyes Protection Reminder</h1>
   </div>
}